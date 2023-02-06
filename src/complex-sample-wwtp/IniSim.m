function y_out = IniSim()
    in = Simulink.SimulationInput('Modelo_Simulink_2021b');
    evalin('base', 'ini_Params');
    assignin('base', 'init', true);
    y_out = 1;
end

