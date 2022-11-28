# Install Matlab On Linux

1. Log in to [Mathworks](https://matlab.mathworks.com/):

    > **Note**: Since MATLAB is proprietary software, we need a license to use it.

    - After verification is completed, you will be greeted with the MATLAB Dashboard where you can download the software.

    ![image](./images/Matlab_Dashboard-1024x448.png.webp)

2. Downloading MATLAB

    To download MATLAB, click the [“Install MATLAB on your computer”](https://in.mathworks.com/downloads/web_downloads/10192509) and then “Download for Linux”.

    ![image](./images/Matlab_Linux_download-768x435.png.webp)

    This will download a zip file that contains your MATLAB software.

3. Install MATLAB

    - To install MATLAB, we must first unzip the downloaded folder. However, before unzipping, we will first make a separate folder, in which we can unzip the downloaded folder. I have named that folder "MATLAB" but it can be named anything.

    ```console
    mkdir MATLAB
    unzip matlab_R2022a_glnxa64.zip -d MATLAB
    ```

    - Now, go to the folder in which you unzipped all the files and execute the install script:

    ```console
    cd MATLAB
    ./install 
    ```

    - This will prompt an installation wizard asking you to log in.

    ![image](./images/Matlab_Installer-768x712.png)