# How to deploy a Simulink model as Standalone Applications into Docker Images

The following repository is intended to document the procedure to deploy a Simulink model as a Standalone Application in a Docker container.

## I. Components installation

1. [Deployment basic requirements](./documentation/BasicReq.md). **[Required]**
2. [Install Matlab on Linux OS](./documentation/MatlabOnLinux.md). **[Required]**

## II. From compiler Matlab to Docker container

> **Note:** It is recommended to perform this step before step III.

|<img src="./documentation/images/CompilerToDocker.png"  width=60% height=60%>|
|:---------------------------------------------------------------------------:|

1. [Built a Basic function on Docker](./documentation/BasicFunctionDocker.md). **[Optional: only for testing purposes]**
2. [Built a Simulink Model on Docker](./documentation/SimuDockerDep.md). **[Optional: only for testing purposes]**.
3. [Built a Simulink Model with S-Fuctions on Docker](./documentation/SimS-FunctDockerDep.md). **[Optional: only for testing purposes]**
4. [Built a  more complex Simulink Model with S-Functions on Docker](./documentation/ComplexSampleWWTPDockerDep.md). **[Required]**

## III. From compiler to Microservice

1. [Microservice of a Basic function](./documentation/BasicFunctionRESTDocker.md). **[Optional: only for testing purposes]**
2. [Microservice of a basic Simulink Model](./documentation/SimuRESTDocker.md). **[Optional: only for testing purposes]**.
3. [Microservice of a Simulink Model with S-Fuctions](./documentation/SimS-FunctRESTDocker.md). **[Optional: only for testing purposes]**
4. [Microservice of a more complex Simulink Model with S-Fuctions](./documentation/ComplexSampleWWTPRESTDocker.md). **[Required]**

|<img src="./documentation/images/CompilerToRESTToDocker.png"  width=80% height=80%>|
|:---------------------------------------------------------------------------------:|

## Add-on

1. [Calculation of model execution time](./documentation/ExecutionTime.md)

## To-do


