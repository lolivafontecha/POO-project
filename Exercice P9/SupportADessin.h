#pragma once		

class Ressort;
class Pendule;
class Systeme;

class SupportADessin
{
 public:
  virtual ~SupportADessin() {} // destructeur

  virtual void dessine(Pendule const& pendule) = 0;
  virtual void dessine(Ressort const& ressort) = 0;
  virtual void dessine(Systeme const& systeme) = 0;
};
