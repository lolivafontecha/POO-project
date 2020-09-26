#pragma once			
#include "SupportADessin.h"

class TextViewer : public SupportADessin {
	 public:
	TextViewer(std::ostream& flot) : flot(flot) {}
	
	virtual void dessine(Pendule const& a_dessiner) override;
	virtual void dessine(Ressort const& a_dessiner) override;
	virtual void dessine(Systeme const& a_dessiner) override;

	virtual ~TextViewer() {}

	 private:
	std::ostream& flot;
};




