#pragma once			
#include <iostream>

class SupportADessin;

class Dessinable {
	 protected:
	SupportADessin* support;

	 public: 
	Dessinable(SupportADessin* support): support(support) {} // constructeur
	Dessinable(){}
	virtual void dessine() = 0;
	virtual ~Dessinable() {} // destructeur
};
 
