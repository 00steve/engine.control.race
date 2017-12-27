#include "Race.h"

Race::Race(){
}

Race::~Race(){
    cout << "[delete] race > ";
}


void Race::OnSetSettings(){
    //Settings().Print();
    EngineControl::OnSetSettings();
    PhysicsWorld::PhysicsSettings(Settings());


}




bool Race::HandleMessage(NodeMessage message){
    switch(message.code){
    case MESSAGE_REGISTER_PHYSICS_REQUEST:
        CreateAndSendMessage(message.sender,MESSAGE_REGISTER_PHYSICS_FINISHED,(void*)BuildPhysicsGroup((VarMap*)message.data,(void*)message.sender));
        return true;
    }
    return EngineControl::HandleMessage(message);
}



Node* Race::Child(Node* newChild){
    EngineControl::Child(newChild);
    CreateAndSendMessage(newChild,MESSAGE_REGISTER_PHYSICS_OFFER,NULL);
    return newChild;
}

void Race::Update(){
    EngineControl::Update();
    PhysicsWorld::Step();
}



void Race::Draw(){
    EngineControl::Draw();
}
