# Measurement of the Model Execution time

- To measure the model execution time, Matlab's [tic/toc tools](https://es.mathworks.com/help/matlab/matlab_prog/measure-performance-of-your-program.html) are used.

## How to use the tool

- `RunScript` original code:

    ```console
    function y_out = RunScript()
        in = Simulink.SimulationInput('Remedy_WWTP_OL_FMU_2021b');

        evalin('base', 'ini_DN');
        evalin('base', 'load input_Data.mat');

        in = simulink.compiler.configureForDeployment(in);
        out = sim(in);

        y_out = out.N_sensors(:,5);

    end
    ```

- `RunScript` with timer added:

    ```console
    tStart = tic;           % pair 2: tic

    function y_out = RunScript()
        in = Simulink.SimulationInput('Remedy_WWTP_OL_FMU_2021b');
    
        evalin('base', 'ini_DN');
        evalin('base', 'load input_Data.mat');
    
        in = simulink.compiler.configureForDeployment(in);
        out = sim(in);
    
        y_out = out.N_sensors(:,5);

        tEnd = toc(tStart)      % pair 2: toc
    end
    ```