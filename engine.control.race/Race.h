#ifndef RACE_ENGINE_CONTROL_H
#define RACE_ENGINE_CONTROL_H

#include <gl/glu.h>
#include <engine/core/enginecontrol.h>
#include <engine/core/double3.h>
#include <engine/graphics/camera.h>
#include <engine/physics/physics_world.h>

class Race : public EngineControl, public PhysicsWorld{

protected:

    virtual void OnSetSettings();
    virtual Node* Child(Node* newChild);
    virtual bool HandleMessage(NodeMessage message);

public:

    Race();
    ~Race();

	void Draw();
	void Update();

};

#endif // RACE_H
