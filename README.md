# 1D-Numerical-Solver-DOE-Tool-for-Coupled-Inductors-with-Nonlinear-Magnetic-Circuits-in-C-
1D numerical solver and C++ DOE tool for optimizing coupled inductor geometries using non-linear magnetic circuit analysis (B-H curve).

## Overview

Coupled inductors are widely used in multi-phase DC-DC converters to achieve compact sizing and high efficiency. However, designing these components involves complex trade-offs due to magnetic coupling (self and mutual inductances), spatial layout constraints, and non-linear core saturation behaviors ($B-H$ curve).

This repository provides a fast 1D numerical solver written in C++. It models non-linear magnetic circuits based on Hopkinson's law (Ohm's law for magnetic circuits) and Kirchhoff's magnetic flux law. The tool allows power electronics and magnetics engineers to execute multi-parameter sweeps (Design of Experiments / DOE) across tens of thousands of geometry combinations to identify optimal Pareto-front designs prior to running time-consuming 3D Finite Element Method (FEM) simulations.

---

## Key Features

- **Nonlinear Magnetic Circuit Solver**:
  - Solves transient and steady-state magnetic states using dynamic $B-H$ material characteristics.
  - Accounts for multi-path flux leakage, gap reluctance, and saturation effects across various core segments.
  - Computes time-varying current waveforms, self-inductance ($L$), mutual inductance ($M$), and magnetic flux density ($B$).

- **High-Performance C++ DOE Framework**:
  - Sweeps multiple structural and material parameters (core dimensions, air-gap thickness, turn counts, wire dimensions, etc.).
  - Evaluates performance metrics (core loss, copper loss, total volume, peak/ripple currents).
  - Filters out candidates violating operating thresholds and ranks top-performing candidates.

- **Fast Design Space Screening**:
  - Reduces optimization time from days (using 3D FEM) to minutes by leveraging 1D equivalent circuit formulations.

---

## Physics & Methodology

1. **Equivalence & Governing Equations**:
   - Magnetomotive Force (MMF): $F = N \cdot I$
   - Magnetic Reluctance: $R_m = \frac{l}{\mu(B) \cdot A}$
   - Ohm's Law for Magnetic Circuits: $\Phi = \frac{F}{R_m}$
   - Kirchhoff's Flux Law at circuit nodes: $\sum \Phi = 0$

2. **Non-linear Transient Analysis**:
   - At each time step $\Delta t$, permeability $\mu(B)$ is updated non-linearly using $B-H$ look-up tables or interpolation functions.
   - The system solves the coupled differential equation $V = N \frac{d\Phi}{dt}$ to track current derivatives $\frac{di}{dt}$ and magnetic flux updates.

3. **Loss Estimation**:
   - **Copper Loss ($P_{cu}$)**: Calculated based on temperature-dependent winding resistance and RMS current.
   - **Core Loss ($P_{fe}$)**: Estimated from dynamic flux density variations using Steinmetz-based or empirical core loss parameters.

---

## Repository Structure

```text
├── CMakeLists.txt
├── README.md
├── config/
│   ├── sample_bh_curve.csv       # Sample B-H material data
│   └── parameter_sweep_config.csv # Input parameter ranges for DOE
├── docs/
│   └── magnetic_circuit_formulation.pdf  # Theoretical background & equations
├── include/
│   ├── MagneticCircuit.hpp
│   └── Solver.hpp
├── src/
│   ├── MagneticCircuit.cpp
│   ├── Solver.cpp
│   └── main.cpp
└── scripts/
    └── plot_pareto.py            # Python script to visualize loss vs. volume
