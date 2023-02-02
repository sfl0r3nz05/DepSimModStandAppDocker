function y_out = RunScript()
    in = Simulink.SimulationInput('Remedy_WWTP_OL_FMU_2021b');

    evalin('base', 'ini_DN');
    evalin('base', 'load Input_Data.mat');

    in = simulink.compiler.configureForDeployment(in);
    out = sim(in);

    y_out = out.N_sensors(:,5);

end
