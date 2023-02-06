function y_out = RunSim(P_in, I_in)
    
    ise = evalin('base', 'exist(''init'', ''var'') == 1');

    if (ise == 1)
        in = Simulink.SimulationInput('Modelo_Simulink_2021b');

        assignin('base', 'P_val', P_in);
        assignin('base', 'I_val', I_in);

        % in = simulink.compiler.configureForDeployment(in);
        out = sim(in);
        y_out = out.Results;
    else
        y_out = -1;
end