#include "GamePCH.h"
#include "PlayerController.h" 

void PlayerController::OnEvent(fw::InputEvent* ie)
{

    if (ie->GetID() == VK_DOWN)
    {
        if (ie->GetState() == fw::KeyStates::Pressed)
            dwFlag = 1;
        else if (ie->GetState() == fw::KeyStates::Release)
            dwFlag = 0;
    }

    if (ie->GetID() == VK_UP)
    {
        if (ie->GetState() == fw::KeyStates::Pressed)
            upFlag = 1;
        else if (ie->GetState() == fw::KeyStates::Release)
            upFlag = 0;
    }

    if (ie->GetID() == VK_RIGHT)
    {
        if (ie->GetState() == fw::KeyStates::Pressed)
            rtFlag = 1;
        else if (ie->GetState() == fw::KeyStates::Release)
            rtFlag = 0;
    }

    if (ie->GetID() == VK_LEFT)
    {
        if (ie->GetState() == fw::KeyStates::Pressed)
            lfFlag = 1;
        else if (ie->GetState() == fw::KeyStates::Release)
            lfFlag = 0;
    }
}
