# How to deploy a Simulink model as Standalone Applications into Docker Images

The following repository is intended to document the procedure to deploy a Simulink model as a Standalone Application in a Docker container.

## I. Components installation

1. [Deployment basic requirements](./documentation/BasicReq.md). **[Required]**
2. [Install Matlab on Linux OS](./documentation/MatlabOnLinux.md). **[Required]**

## II. From compiler Matlab to Docker container

> **Note:** It is recommended to perform this step before step III.

|<img src="./documentation/images/CompilerToDocker.png"  width=50% height=50%>|
|:---------------------------------------------------------------------------:|

1. [Test the deployment](./documentation/PackageMatlabApplication.md). **[Optional: only for testing purposes]**
2. [Deploy Simulink Model](./documentation/SimuDockerDep.md). **[Optional: only for testing purposes]**.
3. [Deploy Simulink Model with S-Fuctions](./documentation/SimS-FunctDockerDep.md) **[Required]**

## III. From compiler to Microservice

## Add-on

1. [Model Execution time](./documentation/ExecutionTime.md)

## To-do

1. [Create Microservice Docker Image](https://es.mathworks.com/help/compiler_sdk/mps_dev_test/create-a-microservice-docker-image.html)