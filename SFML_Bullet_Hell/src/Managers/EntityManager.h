#pragma once
#include "Objects/GameObject.h"

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

private:
	std::map<std::string, GameObject*> m_entities;
};

