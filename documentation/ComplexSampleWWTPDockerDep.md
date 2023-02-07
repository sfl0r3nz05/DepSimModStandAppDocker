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
    ini_Params()
    ```

    - Expected Output:

    | |
    |:---------:|
    |![image](https://user-images.githubusercontent.com/6643905/217027278-5698ea81-b132-4658-8515-34b88980f911.png)|

4. Open Simulink project: `Modelo_Simulink_WWTP_2021b.slx` and run it

    - Expected Output:

    | |
    |:---------:|
    |![image](https://user-images.githubusercontent.com/6643905/217029496-c789358c-5ec7-4a27-b8cc-e002143f9639.png)|

    | |
    |:---------:|
    |![image](https://user-images.githubusercontent.com/6643905/217171619-7a598f0b-cdde-4eea-92ec-fb2f3b341b76.png)|


5. Run the `IniSim` fuction: `IniSim()`

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
    Build Summary

    0 of 1 models built (1 models already up to date)
    Build duration: 0h 0m 1.1454s

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


7. Launch the `RunSim.m` compilation including the `AdditionalFiles` property:

    ```console
    res = compiler.build.standaloneApplication('RunSim.m', 'TreatInputsAsNumeric', true, 'AdditionalFiles', ["IniSim.m","ini_Params.m"])
    ```

    - Expected Output:

    ```console
    ### Building the rapid accelerator target for model: Modelo_Simulink_WWTP_2021b
    ### Successfully built the rapid accelerator target for model: Modelo_Simulink_WWTP_2021b

    Build Summary

    Top model rapid accelerator targets built:

    Model                       Action                       Rebuild Reason                                    
    ===========================================================================================================
    Modelo_Simulink_WWTP_2021b  Code generated and compiled  Code generation information file does not exist.  

    1 of 1 models built (0 models already up to date)
    Build duration: 0h 0m 4.7637s

    res = 

      Results with properties:

                      BuildType: 'standaloneApplication'
                         Files: {3×1 cell}
        IncludedSupportPackages: {}
                        Options: [1×1 compiler.build.StandaloneApplicationOptions]
    ```

8. Package Standalone Application into Docker Image:

    ```console
    opts = compiler.package.DockerOptions(res, 'ImageName', 'sflorenz05/depsimmodstandappdocker/complex_sample_wwtp:v0.1')
    ```

    - Expected Output:

    ```console
    opts = 

      DockerOptions with properties:

                EntryPoint: 'RunSim'
        ExecuteDockerBuild: on
                 ImageName: 'sflorenz05/depsimmodstandappdocker/complex_sample_wwtp:v0.1'
             DockerContext: './sflorenz05/depsimmodstandappdocker/complex_sample_wwtp:v0.1docker'
    ```

9. Create a Docker Image

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


    DOCKER CONTEXT LOCATION:

    /home/usuario/DepSimModStandAppDocker/src/complex-sample-wwtp/sflorenz05/depsimmodstandappdocker/complex_sample_wwtp:v0.1docker

    SAMPLE DOCKER RUN COMMAND:

    docker run --rm -e "DISPLAY=localhost:10.0" -v /tmp/.X11-unix:/tmp/.X11-unix sflorenz05/depsimmodstandappdocker/complex_sample_wwtp:v0.1

    EXECUTE xhost + ON THE HOST MACHINE TO VIEW CONTAINER GRAPHICS
    ```

10. Command window sample:

    | |
    |:---------:|
    |![image](https://user-images.githubusercontent.com/6643905/217174215-0225c53d-4ec2-4453-bc5e-6cc1ee3d3e1a.png)|

11. Test the container

    ```console
    docker run --rm -e "DISPLAY=localhost:10.0" -v /tmp/.X11-unix:/tmp/.X11-unix sflorenz05/depsimmodstandappdocker/complex_sample_wwtp:v0.1 --logs
    ```