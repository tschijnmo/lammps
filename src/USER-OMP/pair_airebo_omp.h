/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------
   Contributing author: Axel Kohlmeyer (Temple U)
------------------------------------------------------------------------- */

#ifdef PAIR_CLASS

PairStyle(airebo/omp,PairAIREBOOMP)

#else

#ifndef LMP_PAIR_AIREBO_OMP_H
#define LMP_PAIR_AIREBO_OMP_H

#include "pair_airebo.h"
#include "thr_omp.h"

namespace LAMMPS_NS {

class PairAIREBOOMP : public PairAIREBO, public ThrOMP {

 public:
  PairAIREBOOMP(class LAMMPS *);

  virtual void compute(int, int);
  virtual double memory_usage();

 protected:
  double bondorder_thr(int i, int j, double rij[3], double rijmag,
		     double VA, double **f, int vflag_atom, int tid);
  double bondorderLJ_thr(int i, int j, double rij[3], double rijmag,
		       double VA, double rij0[3], double rijmag0,
		       double **f, int vflag_atom, int tid);

  void FREBO_thr(double **f, int ifrom, int ito,
		 int evflag, int eflag, int vflag_atom, int tid);
  void FLJ_thr(double **f, int ifrom, int ito,
	       int evflag, int eflag, int vflag_atom, int tid);
  void TORSION_thr(double **f, int ifrom, int ito,
		   int evflag, int eflag, int tid);
  void REBO_neigh_thr();
};

}

#endif
#endif
