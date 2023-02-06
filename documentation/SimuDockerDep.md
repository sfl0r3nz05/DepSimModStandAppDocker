# Simulink Project To Docker Deployment

## Create the Docker container **[On the VM where Matlab is installed]**

1. Clone the repository: `git clone https://github.com/sfl0r3nz05/DepSimModStandAppDocker.git`
2. Go into the project folder `cd ~/DistributedBchFWArchIoT/src/simple_simulink_proj` using Matlab:

    | |
    |:-------------------------------:|
    |![image](https://user-images.githubusercontent.com/6643905/216972286-c134e690-52ab-4d52-8d46-0d60566b156e.png) |

3. Test the `RunScript` function on the Matlab cmd:

    ```console
    RunScript()
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
    Build duration: 0h 0m 8.0539s

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
    0.2000    0.3402
    0.2100    0.3488
    0.2200    0.3563
    0.2300    0.3629
    0.2400    0.3684
    0.2500    0.3732
   ...        ...
             
    ```

4. Launch the `RunScript.m` compilation:

    ```console
    res = compiler.build.standaloneApplication('RunScript.m', 'TreatInputsAsNumeric', true)
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
    Build duration: 0h 0m 3.8855s

    res = 

      Results with properties:

                     BuildType: 'standaloneApplication'
                         Files: {3×1 cell}
        IncludedSupportPackages: {}
                         Options: [1×1 compiler.build.StandaloneApplicationOptions]
    ```

5. Package Standalone Application into Docker Image:

    ```console
    opts = compiler.package.DockerOptions(res, 'ImageName', 'sflorenz05/depsimmodstandappdocker/simple_simulink_proj:v0.1')
    ```

    - Expected Output:

    ```console

    opts = 

      DockerOptions with properties:

              EntryPoint: 'RunScript'
        ExecuteDockerBuild: on
                 ImageName: 'sflorenz05/depsimmodstandappdocker/simple_simulink_proj:v0.1'
            DockerContext: './sflorenz05/depsimmodstandappdocker/simple_simulink_proj:v0.1docker'
    ```

6. Create a Docker Image

    ```console
    compiler.package.docker(res, 'Options', opts)
    ```

    - Expected Output:

    ```console
    DOCKER CONTEXT LOCATION:

    /home/usuario/DepSimModStandAppDocker/src/simple_simulink_proj/sflorenz05/depsimmodstandappdocker/simple_simulink_proj:v0.1docker

    SAMPLE DOCKER RUN COMMAND:

    docker run --rm -e "DISPLAY=localhost:10.0" -v /tmp/.X11-unix:/tmp/.X11-unix sflorenz05/depsimmodstandappdocker/simple_simulink_proj:v0.1

    EXECUTE xhost + ON THE HOST MACHINE TO VIEW CONTAINER GRAPHICS.
    ```

    |     **Matlab Project Overview**     |
    |:-----------------------------------:|
    |  ![image](https://user-images.githubusercontent.com/6643905/216983398-5443f9f8-76ad-4179-9d99-874b030a8ae7.png)  |

7. Test the Docker Image

    ```console
    docker images -a
    ```

    - Expected Output:

    ```console
    REPOSITORY                                                TAG       IMAGE ID       CREATED          SIZE
    sflorenz05/depsimmodstandappdocker/simple_simulink_proj   v0.1      25ec0170404d   11 minutes ago   3.22GB
    ```

8. Run the `sflorenz05/depsimmodstandappdocker/simple_simulink_proj:v0.1` image:

    ```console
    docker run --rm -e "DISPLAY=localhost:10.0" -v /tmp/.X11-unix:/tmp/.X11-unix sflorenz05/depsimmodstandappdocker/simple_simulink_proj:v0.1
    ```

    - Expected Output:

    ```console
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
        ......    ......
        ......    ......
        ......    ...... 
    ```

