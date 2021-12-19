#include "AIComponent.h"
#include "Actor.h"
#include "AIState.h"
#include <SDL/SDL_Log.h"

AIComponent::AIComponent(class Actor* owner)
:Component(owner)
,mCurrentState(nullptr)
{
}

void AIComponent::Update(float deltaTime)
{
    if (mCurrentState)
    {
        mCurrentState->Update(deltaTime);
    }
}

void AIComponent::ChangeState(const std::string& name)
{
    // First exit the current state
    if (mCurrentState)
    {
        mCurrentState->OnExit();
    }
    
    // Try to find the new state from the map
    auto iter = mStateMap.find(name);
    if (iter != mStateMap.end())
    {
        mCurrentState = iter->second;
        // We're entering the new state
        mCurrentState->OnEnter();
    }
    else
    {
        SDL_Log("Could not find AIState %s in state map", name.c_str());
        mCurrentState = nullptr;
    }
}

void AIComponent::RegisterState(AIState* state)
{
    mStateMap.emplace(state->GetName(), state);
}
