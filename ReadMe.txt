"Multi-rotor wind turbine control challenge - A benchmark for advanced control development"

To run this simulation environment:
1. Run psetup in Matlab - Add paths to Vestas functions and SimWindFarm toolbox
2. Run SimulationMain.m to generate baseline results, Vestas benchmark results, and your own benchmark
	2a. Change variable "SimName = 'YOUR_SIMULATION_NAME'" depending on what simulation to run e.g. baseline or with specific control feature enabled
	2b. Change Px_AddExternalDeltaPitch=1 to enable Vestas control
	3c. Change Px_UseExternalTower=1 to use multi-rotor structure tower else use standard monopile tower.
3. After running model, results is generated here: "..\mrtcc\results\YOUR_SIMULATION_NAME" based on your controller.
4. Run AnimationMain.m to animate benchmark vs. baseline or just baseline.
5. After baseline and new designed benchmark controller is simulated the results can be compared with PostProcessMain. It generated a table called ResCompare which contains the ratios between baseline and benchmark parameters.

This is developed in Matlab 2016b.

Any questions: kihso@vestas.com
