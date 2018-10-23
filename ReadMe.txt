"Multi-rotor wind turbine control challenge - A benchmark for advanced control development"

To run this simulation model:
1. Run psetup in Matlab - Add paths to Vestas functions and SimWindFarm toolbox
2. Run Main.m to generate data
	2a. Change "SimName" depending on what simulation to run e.g. baseline or with control aka benchmark
	2b. Change Px_AddExternalDeltaPitch=1 to enable Vestas control
	3c. Change Px_UseExternalTower=1 to use multi-rotor structure tower else use standard monopile tower.
3. After running model, results folder with data is generated.
4. Run AnimationMain.m to animate benchmark vs. baseline or just baseline.

Any questions: kihso@vestas.com



