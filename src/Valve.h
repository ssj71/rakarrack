/*
  ZynAddSubFX - a software synthesizer
  Based on valve Steve Harris LADSPA plugin.
  Valve.h - Distorsion Effect
  Copyright (C) 2002-2005 Nasca Octavian Paul
  Author: Nasca Octavian Paul

  Modified for rakarrack by Josep Andreu & Hernan Ordiales
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of version 2 of the GNU General Public License 
  as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License (version 2) for more details.

  You should have received a copy of the GNU General Public License (version 2)
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/

#ifndef VALVE_H
#define VALVE_H

#include "global.h"
#include "AnalogFilter.h"


class Valve
{
public:
  Valve (REALTYPE * efxoutl_, REALTYPE * efxoutr_);
  ~Valve ();
  void out (REALTYPE * smpsl, REALTYPE * smpr);
  void setpreset (int npreset);
  void changepar (int npar, int value);
  int getpar (int npar);
  void cleanup ();
  void applyfilters (REALTYPE * efxoutl, REALTYPE * efxoutr);

  int Ppreset;
  REALTYPE *efxoutl;
  REALTYPE *efxoutr;
  REALTYPE *octoutl;
  REALTYPE *octoutr;
  REALTYPE outvolume;
  REALTYPE volume;

private:


  //Parametrii
  int Pvolume;	//Volumul or E/R
  int Ppanning;	//Panning
  int Plrcross;	// L/R Mixing
  int Pdrive;		//the input amplification
  int Plevel;		//the ouput amplification
  int Pnegate;	//if the input is negated 
  int Plpf;		//lowpass filter
  int Phpf;		//highpass filter
  int Pstereo;	//0=mono,1=stereo
  int Pprefiltering;	//if you want to do the filtering before the distorsion
  int Q_q;
  
  void setvolume (int Pvolume);
  void setpanning (int Ppanning);
  void setlrcross (int Plrcross);
  void setlpf (int Plpf);
  void sethpf (int Phpf);

  //Parametrii reali
  REALTYPE panning, lrcross, q, dist, otml,otmr, itml, itmr;
  AnalogFilter *lpfl, *lpfr, *hpfl, *hpfr;

};


#endif
