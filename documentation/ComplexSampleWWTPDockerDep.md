# Simulink Project with S-Function for a more complex WWTP To Docker Deployment

This tutorial help to compile and containerize the next Simulink Project:

![img](https://user-images.githubusercontent.com/6643905/217027408-7362c254-d1fc-4a44-99a1-8417465e9262.png)

## Create the Docker container **[On the VM where Matlab is installed]**

1. Clone the repository: `git clone https://github.com/sfl0r3nz05/DepSimModStandAppDocker.git`
2. Go into the project folder `cd ~/DistributedBchFWArchIoT/src/complex-sample-wwtp` using Matlab:

    | |
    |:---------:|
    |![image](https://user-images.githubusercontent.com/6643905/217028428-34bb1dfe-2801-4e36-95a6-eaa27b8eb1c2.png)|

3. Initialize project variables

    ```console
    ini_Param()
    ```

    - Expected Output:

    | |
    |:---------:|
    |![image](https://user-images.githubusercontent.com/6643905/217027278-5698ea81-b132-4658-8515-34b88980f911.png)|

4. Open Simulink project: `Modelo_Simulink_WWTP_2021b.slx`

    - Expected Output:

    | |
    |:---------:|
    |![image](https://user-images.githubusercontent.com/6643905/217029496-c789358c-5ec7-4a27-b8cc-e002143f9639.png)|


5. Run the `iniSim` fuction: `IniSim()`

    - Expected Output:

    ```console
    >> IniSim()

    ans =

         1
    ```

6. Run the `RunSim` function: `RunSim(5,2)`

    - Expected Output:

    ```console
    >> RunSim(5,2)
    ### Building the rapid accelerator target for model: Modelo_Simulink_2021b
    ### Successfully built the rapid accelerator target for model: Modelo_Simulink_2021b

    Build Summary

    Top model rapid accelerator targets built:

    Model                  Action                       Rebuild Reason                                    
    ======================================================================================================
    Modelo_Simulink_2021b  Code generated and compiled  Code generation information file does not exist.  

    1 of 1 models built (0 models already up to date)
    Build duration: 0h 0m 3.9714s

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
        0.1100    0.2061
        0.1200    0.2263
        0.1300    0.2452
        0.1400    0.2627
        0.1500    0.2790
        0.1600    0.2938
        0.1700    0.3073
        0.1800    0.3195
        0.1900    0.3305
        ......    ......
    ```


7. Launch the `RunScript.m` compilation including the `AdditionalFiles` property:

    ```console
    res = compiler.build.standaloneApplication('RunSim.m', 'TreatInputsAsNumeric', true, 'AdditionalFiles', ["IniSim.m","ini_Params.m"])
    ```

    - Expected Output:

    ```console
    ### Building the rapid accelerator target for model: Modelo_Simulink_2021b
    ### Successfully built the rapid accelerator target for model: Modelo_Simulink_2021b

    Build Summary

    Top model rapid accelerator targets built:

    Model                  Action                       Rebuild Reason                                    
    ======================================================================================================
    Modelo_Simulink_2021b  Code generated and compiled  Code generation information file does not exist.  

    1 of 1 models built (0 models already up to date)
    Build duration: 0h 0m 5.1664s

    res = 

      Results with properties:

                     BuildType: 'standaloneApplication'
                          Files: {3×1 cell}
        IncludedSupportPackages: {}
                        Options: [1×1 compiler.build.StandaloneApplicationOptions]
    ```

11. Package Standalone Application into Docker Image:

    ```console
    opts = compiler.package.DockerOptions(res, 'ImageName', 'sflorenz05/depsimmodstandappdocker/sample_wwtp')
    ```

    - Expected Output:

    ```console
    opts =

      DockerOptions with properties:

                EntryPoint: 'RunScript'
        ExecuteDockerBuild: on
                 ImageName: 'sflorenz05/depsimmodstandappdocker/wwtp'
             DockerContext: './sflorenz05/depsimmodstandappdocker/sample_wwtpdocker'
    ```

12. Create a Docker Image

    ```console
    compiler.package.docker(res, 'Options', opts)
    ```

    - Expected Output:

    ```console
    Runtime Image Already Exists
    Sending build context to Docker daemon  557.1kB
    Sending build context to Docker daemon  4.456MB
    Sending build context to Docker daemon  8.356MB
    Sending build context to Docker daemon   11.1MB


    Step 1/6 : FROM matlabruntime/r2022a/release/update5/e0000000000000200
     ---> dc12891158c3
    Step 2/6 : COPY ./applicationFilesForMATLABCompiler /usr/bin/mlrtapp
     ---> 4f44e9169b92
    Step 3/6 : RUN chmod -R a+rX /usr/bin/mlrtapp/*
     ---> Running in 6b4a3b40dcc5
    Removing intermediate container 6b4a3b40dcc5
     ---> 4c7c29a2253f
    Step 4/6 : RUN useradd -ms /bin/bash appuser
     ---> Running in bea321274686
    Removing intermediate container bea321274686
     ---> 93744760564e
    Step 5/6 : USER appuser
     ---> Running in 5abe48e76ae1
    Removing intermediate container 5abe48e76ae1
     ---> a1b25420b905
    Step 6/6 : ENTRYPOINT ["/usr/bin/mlrtapp/RunScript"]
     ---> Running in 99ad37ccca31
    Removing intermediate container 99ad37ccca31
     ---> 63eff14be9e5
    Successfully built 63eff14be9e5
    Successfully tagged sflorenz05/wwtp:latest

    DOCKER CONTEXT LOCATION:

    /home/ubuntu/matlab_model/TestSFunction/sflorenz05/wwtpdocker

    SAMPLE DOCKER RUN COMMAND:

    docker run --rm -e "DISPLAY=:0" -v /tmp/.X11-unix:/tmp/.X11-unix sflorenz05/wwtp

    EXECUTE xhost + ON THE HOST MACHINE TO VIEW CONTAINER GRAPHICS.
    ```

13. Command window sample:

    |        ![img](./images/full_proj.png)        |
    |:--------------------------------------------:|
    |          **Full Project Overview**           |
