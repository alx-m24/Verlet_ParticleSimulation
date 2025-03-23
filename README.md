
# Verlet Particle Simulation
This is a C++ implementation of a Verlet-based particle simulation using the SFML graphics library. The simulation efficiently handles particle interactions using grid partitioning for spatial acceleration and multithreading for improved performance.

# Features
Verlet Integration: A stable physics simulation method for smooth and realistic particle motion.

- Grid Partitioning: Efficiently optimizes collision detection by dividing the simulation space into grid cells.

- Multithreading: Improves performance by parallelizing particle updates.

- SFML Rendering: Uses SFML to visualize particle movement in real time.

# Dependencies
SFML (Simple and Fast Multimedia Library)

# Installation & Compilation
Ensure you have SFML installed.

# How It Works
- Physics: The simulation follows Verlet integration, where positions are updated based on previous positions and applied constraints.

- Grid Partitioning: The space is divided into uniform grid cells, reducing the number of collision checks between particles.

- Threading: Particle updates are processed in parallel using multithreading, significantly improving performance with large numbers of particles.

License
This project is open-source and available under the MIT License.
