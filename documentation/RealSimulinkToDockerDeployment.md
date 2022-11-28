# Real Simulink Project To Docker Deployment

## Leave registration of the model and the function in this repository **[On the PC where the repository is cloned]**

1. Create a new folder in the `src` Project folder:

    ```console
    cd ~/DepSimModStandAppDocker/src/
    mkdir ~/DepSimModStandAppDocker/src/WWTP
    ```

2. Copy the `.slx` and `.m` in the created folder. E.g.: `~/DepSimModStandAppDocker/src/WWTP`.

## Use the model and the function on Matlab installation **[On the VM where Matlab is installed]**

1. Create a folder for the model deployment: `mkdir ~/matlab_model/RunScript`.
2. Copy the `.slx` and `.m` in the created folder. E.g.: `~/matlab_model/RunScript`. *See copied files image*.
3. Test the `RunScript` function:

    ```console
    RunScript()
    ```

    - Expected Output:

    ```console
    >> RunScript()
    ### Building the rapid accelerator target for model: Modelo_Simulink_2021b
    ### Successfully built the rapid accelerator target for model: Modelo_Simulink_2021b

    Build Summary

    Top model rapid accelerator targets built:

    Model                  Action                       Rebuild Reason                                    
    ======================================================================================================
    Modelo_Simulink_2021b  Code generated and compiled  Code generation information file does not exist.  

    1 of 1 models built (0 models already up to date)
    Build duration: 0h 0m 25.231s

    ans =

             0         0
        0.0100    0.0040
        0.0200    0.0146
        0.0300    0.0302
        0.0400    0.0491
        0.0500    0.0704
        0.0600    0.0930
        0.0700    0.1163
        0.0800    0.1396
        0.0900    0.1626
        0.1000    0.1848
        ......    ......
        ......    ......
        ......    ......        
    ```

|        **Copied files**         |
|:-------------------------------:|
|![image](./images/RunScript.png) |