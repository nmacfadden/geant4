//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
// $Id: G4DNABrennerAngularDistributionPolicy.hh,v 1.2 2006/06/29 19:33:38 gunter Exp $
// GEANT4 tag $Name: geant4-08-02 $
//
// Phys. Med. Biol. 29 N.4 (1983) 443-447

#ifndef   G4DNABRENNERANGULARDISTRIBUTIONPOLICY_HH
 #define  G4DNABRENNERANGULARDISTRIBUTIONPOLICY_HH 1

 #include "globals.hh"
 
 class G4DNABrennerAngularDistributionPolicy
 {
  protected:
                                        G4DNABrennerAngularDistributionPolicy() {}
   virtual                             ~G4DNABrennerAngularDistributionPolicy() {}

   G4double                             RandomizeCosTheta(G4double k, G4int z) const;
   G4bool                               KillIncomingParticle(G4double k) const { return (k<stopAndKillLowEnergyLimit); }
   void                                 BuildFinalStatesData(void) const {}
   
  private:
   G4double                             CalculatePolynomial(G4double k, const G4double *vector, G4int size) const;

   // Hides default constructor and assignment operator as private 
                                        G4DNABrennerAngularDistributionPolicy(const G4DNABrennerAngularDistributionPolicy & copy);
   G4DNABrennerAngularDistributionPolicy & operator=(const G4DNABrennerAngularDistributionPolicy & right);
   
   static const G4double                stopAndKillLowEnergyLimit;
 };
#endif /* G4DNABRENNERANGULARDISTRIBUTIONPOLICY_HH */
