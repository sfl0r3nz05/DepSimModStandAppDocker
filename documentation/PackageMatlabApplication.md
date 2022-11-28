# Package MATLAB Standalone Applications into Docker Images

This example shows how to package a MATLAB® standalone application into a Docker image.

1. Create a folder for test: `mkdir ~/matlab_model/TestModel`
2. Create Function in MATLAB on `TestModel` folder. See *before compilation image*

    - Write a MATLAB function called `mymagic` and save it with the file name `mymagic.m`.

    ```console
    function mymagic(x)
    y = magic(x);
    disp(y)
    ```

    - Test the function at the MATLAB command prompt.

    ```console
    mymagic(5)
    ```

    - Expected Output:

    ```console
    17    24     1     8    15
    23     5     7    14    16
     4     6    13    20    22
    10    12    19    21     3
    11    18    25     2     9
    ```

3. Create Standalone Application

   - Make the `mymagic` function into a standalone application using the [compiler.build.standaloneApplication](https://es.mathworks.com/help/compiler/compiler.build.standaloneapplication.html) function.

    ```console
    res = compiler.build.standaloneApplication('mymagic.m', 'TreatInputsAsNumeric', true)
    ```

    - Expected Output:

    ```console
    res = 
      Results with properties:

        BuildType: 'standaloneApplication'
            Files: {3×1 cell}
          Options: [1×1 compiler.build.StandaloneApplicationOptions]
    ```

    - Once the build is complete, the function creates a folder named `mymagicstandaloneApplication` in your current directory to store the standalone application. The Results object res returned at the MATLAB command prompt contains information about the build.

    |       **Before compilation**       |        **After compilation**       |      **After Docker Creation**      |
    |:----------------------------------:|:----------------------------------:|:-----------------------------------:|
    |![image](./images/matlab_before.png)| ![image](./images/matlab_after.png)| ![image](./images/matlab_medium.png)|
