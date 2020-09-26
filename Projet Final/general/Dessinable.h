#pragma once

class SupportADessin;

class Dessinable {
	 protected:
	SupportADessin* support;

	 public: 
    Dessinable(SupportADessin* support): support(support) {} // Constructeur
    Dessinable(){} // Constructeur par défaut
	virtual void dessine() = 0;
    virtual ~Dessinable() {} // Destructeur
};
 
