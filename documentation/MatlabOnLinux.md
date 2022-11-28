# Install Matlab On Linux

1. Log in to [Mathworks](https://matlab.mathworks.com/):

    > **Note**: Since MATLAB is proprietary software, we need a license to use it.

    - After verification is completed, you will be greeted with the MATLAB Dashboard where you can download the software.

    ![image](./images/Matlab_Dashboard-1024x448.png.webp)

2. Downloading MATLAB

    - To download MATLAB, click the [“Install MATLAB on your computer”](https://in.mathworks.com/downloads/web_downloads/10192509) and then “Download for Linux”.

    ![image](./images/Matlab_Linux_download-768x435.png.webp)

    - This will download a zip file that contains your MATLAB software.

    - In our case the selected version is `R2022a`.

3. Install MATLAB

    - To install MATLAB, we must first unzip the downloaded folder. However, before unzipping, we will first make a separate folder, in which we can unzip the downloaded folder. I have named that folder "MATLAB" but it can be named anything.

    ```console
    mkdir MATLAB
    unzip matlab_R2022a_glnxa64.zip -d matlab_R2022a_glnxa64
    ```

    - Now, go to the folder in which you unzipped all the files and execute the install script:

    ```console
    cd ~/matlab_R2022a_glnxa64/
    ./install 
    ```

    - This will prompt an installation wizard asking you to log in.

    ![image](./images/Matlab_Installer-768x712.png)

    - After entering the email and password, you will be asked to select your license, select the destination folder, the products you want to install, and whether you want to create symbolic links in the root directory.

    ![image](./images/Destination_folder_matlab-768x583.png.webp)

    - Products installed in our case:

        |       **Product**       | **Is Installed** |
        |:-----------------------:|:----------------:|
        |     MATLAB Compiler     |         X        |
        |       MATLAB Coder      |         X        |
        |   MATLAB Compiler SDK   |         X        |
        | MATLAB Report Generator |         X        |
        |     Mapping Toolbox     |         X        |
        |         Simulink        |         X        |
        |    Simulink Compiler    |         X        |

    > **Note**: It is possible that you don’t have sudo privileges, in which case, the installer will refuse to select /usr/local/ as the destination folder. In that case, you choose /home/ as your destination folder and so no to creating symbolic links.

    - After everything is done, it will install the product.

    ![image](./images/Mathworks_Product_Installer-768x589.png.webp)

4. Launch MATLAB

    - If you made symbolic links during the installation, you can launch Matlab by simply typing matlab in terminal.

    - If you cannot make [symbolic links](https://www.linuxfordevices.com/tutorials/ubuntu/create-symbolic-links-in-ubuntu-linux), then all the launch scripts are placed in the /bin/ folder where you installed MATLAB.

    - To launch MATLAB. Go to the bin folder of the destination directory and execute the following.

    ```console
    cd ~/MATLAB/R2022a/bin/
    ./matlab
    ```

    > **Note**: You may not want to browse to this folder and execute .matlab every time you have to start MATLAB. In that case, you can make an alias (like the one shown below) and add it to ~/.bashrc

    ```console
    alias matlab="~/MATLAB/R2022a/bin/matlab"
    ```

    ![image](./images/matlab_alias-768x656.png)

    - Finally, you have installed MATLAB and can start working on it.

    ![image](./images/Installed_matlab-1024x567.png)
