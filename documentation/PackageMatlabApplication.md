# Package MATLAB Standalone Applications into Docker Images

This example shows how to package a MATLAB® standalone application into a Docker image.

1. Create a folder for test: `mkdir ~/matlab_model/TestModel`
2. Create Function in MATLAB on `TestModel` folder. See *before compilation image*

    Write a MATLAB function called `mymagic` and save it with the file name `mymagic.m`.

    ```console
    function mymagic(x)
    y = magic(x);
    disp(y)
    ```

    |       **Before compilation**       |       **Before compilation**       |
    |:----------------------------------:|:----------------------------------:|
    |![image](./images/matlab_before.png)| ![image](./images/matlab_after.png)|