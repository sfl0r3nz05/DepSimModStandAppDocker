function y_out = RunScript()
    in = Simulink.SimulationInput('Modelo_Simulink_2021b');

    % Coeficientes de los polinomios de numerador y denominador del sistema a controlar G(s)
    num = [87.5];
    assignin('base', 'num', num);
    den = [1 27 25];
    assignin('base', 'den', den);
 
    % Valores las constantes P e I del PI
    P_val = 2.3;
    assignin('base', 'P_val', P_val);
    I_val = 0.75;
    assignin('base', 'I_val', I_val);

    in = simulink.compiler.configureForDeployment(in);
    out = sim(in);

    y_out = out.Results;
    disp(y_out)
end