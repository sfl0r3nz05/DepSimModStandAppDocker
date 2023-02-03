# Create Microservice Docker Image

1. Clone the repository: `git clone https://github.com/sfl0r3nz05/DepSimModStandAppDocker.git`
2. Go into the project folder `cd ~/DistributedBchFWArchIoT/src/sample-wwtp` using Matlab:

   <img width="960" alt="dockerdep4" src="https://user-images.githubusercontent.com/6643905/216677558-f146bf23-0921-408d-8245-08d07cefc671.PNG">

3. Create Deployable Archive

   - Creates a deployable archive with options specified

    ```console
    opts = compiler.build.ProductionServerArchiveOptions('RunScript.m',...
    'ArchiveName','sample_wwtp',...
    'AdditionalFiles',["ini_DN.m","Input_Data.mat"],...
    'AutoDetectDataFiles','on',...
    'Verbose','on')
    ```

    - Expected Output:

    ```console
    opts = 

    ProductionServerArchiveOptions with properties:

              ArchiveName: 'sample_wwtp'
           FunctionFiles: {'/home/usuario/DepSimModStandAppDocker/src/sample-wwtp/RunScript.m'}
       FunctionSignatures: ''
          AdditionalFiles: {'/home/usuario/DepSimModStandAppDocker/src/sample-wwtp/Input_Data.mat'}
      AutoDetectDataFiles: on
          SupportPackages: {'autodetect'}
                  Verbose: on
                OutputDir: './sample_wwtpproductionServerArchive'
    ```

   - Package the `RunScript` function into a deployable archive using the [compiler.build.productionServerArchive](https://es.mathworks.com/help/compiler_sdk/mps_dev_test/compiler.build.productionserverarchive.html) function.

    ```console
    mpsResults=compiler.build.productionServerArchive(opts)
    ```

    - Expected Output:

    ```console
    mcc -W CTF:sample_wwtp -d ./sample_wwtpproductionServerArchive -v -a /home/usuario/DepSimModStandAppDocker/src/sample-wwtp/Input_Data.mat -Z autodetect -U /home/usuario/DepSimModStandAppDocker/src/sample-wwtp/RunScript.m
    Compiler version: 8.4 (R2022a)
    Analyzing file dependencies. 
    ### Generating code and artifacts to 'Model specific' folder structure
    ### Generating code into build folder: /home/usuario/DepSimModStandAppDocker/src/sample-wwtp/slprj/raccel_deploy/Remedy_WWTP_OL_FMU_2021b
    ### Saving binary information cache.

    Build Summary

    0 of 1 models built (1 models already up to date)
    Build duration: 0h 0m 1.4837s
    Parsing file "/home/usuario/DepSimModStandAppDocker/src/sample-wwtp/RunScript.m"
      (referenced from command line).
    Generating file "/home/usuario/DepSimModStandAppDocker/src/sample-wwtp/sample_wwtpproductionServerArchive/readme.txt".

    mpsResults = 

      Results with properties:

                      BuildType: 'productionServerArchive'
                          Files: {'/home/usuario/DepSimModStandAppDocker/src/sample-wwtp/sample_wwtpproductionServerArchive/sample_wwtp.ctf'}
        IncludedSupportPackages: {}
                        Options: [1×1 compiler.build.ProductionServerArchiveOptions]
    ```

    - The compiler.build.Results object mpsResults contains information on the build type, generated files, included support packages, and build options.
    - Once the build is complete, the function creates a folder named `sample_wwtpproductionServerArchive` in your current directory to store the deployable archive.
      - *See the compilation image*

        |<img width="639" alt="dockerdep4" src="https://user-images.githubusercontent.com/6643905/216682017-024835be-0792-4d45-a1e3-bcb4f868e5c2.PNG">|
        |:------------------------------------:|

4. Package Archive into Microservice Docker Image

   - Build the microservice Docker image using the mpsResults object that you created.
   - You can specify additional options in the compiler.build command by using name-value arguments.

    ```console
    compiler.package.microserviceDockerImage(mpsResults,'ImageName','sflorenz05/depsimmodstandappdocker/sample_wwtp_api:v0.1')
    ```

    - Expected Output:

    ```console
    Runtime Image Already Exists
    Sending build context to Docker daemon  34.82kB


    Step 1/6 : FROM matlabruntime/r2022a/release/update5/21000000000000000
      ---> ad58363ceb4a
    Step 2/6 : COPY ./applicationFilesForMATLABCompiler /usr/bin/mlrtapp
      ---> d5bee0724803
    Step 3/6 : RUN chmod -R a+rX /usr/bin/mlrtapp/*
      ---> Running in fcfebc2cff44
    Removing intermediate container fcfebc2cff44
      ---> f1fafe2cc595
    Step 4/6 : RUN useradd -ms /bin/bash appuser
      ---> Running in fe85c3cc0c67
    Removing intermediate container fe85c3cc0c67
      ---> ff1ce2305910
    Step 5/6 : USER appuser
      ---> Running in 6b976bfd4b18
    Removing intermediate container 6b976bfd4b18
      ---> dc0fba8b0a53
    Step 6/6 : ENTRYPOINT ["/opt/matlabruntime/v912/bin/glnxa64/muserve", "-a", "/usr/bin/mlrtapp/magicarchive.ctf"]
      ---> Running in b686805c0d56
    Removing intermediate container b686805c0d56
      ---> 8ec697f512af
    Successfully built 8ec697f512af
    Successfully tagged sflorenz05/depsimmodstandappdocker/sample_wwtp_api:v0.1

    DOCKER CONTEXT LOCATION:

    /home/ubuntu/DepSimModStandAppDocker/src/sflorenz05/depsimmodstandappdocker/sample_wwtpmicroserviceDockerImage


    FOR HELP GETTING STARTED WITH MICROSERVICE IMAGES, PLEASE READ:

    /home/ubuntu/DepSimModStandAppDocker/src/sflorenz05/depsimmodstandappdocker/sample_wwtpmicroserviceDockerImage/GettingStarted.txt
    ```

5. The function generates the following files within a folder named micro-magicmicroserviceDockerImage in your current working directory:

   1. `sflorenz05/depsimmodstandappdocker/applicationFilesForMATLABCompiler/sample_wwtp.ctf` — Deployable archive file.
   2. `Dockerfile` — Docker file that specifies Docker run-time options.
   3. `GettingStarted.txt` — Text file that contains deployment information.
      - *See the packaging image*

          |<img width="181" alt="dockerdep4" src="https://user-images.githubusercontent.com/6643905/216699339-be4c320f-2096-46fd-92f3-8fd26486f93a.PNG">|
          |:----------------------------------------:|

6. Test the image:

    ```console
    docker images -a
    ```

    - Expected Output:

    ```console
    REPOSITORY                                                        TAG       IMAGE ID CREATED             SIZE
    sflorenz05/depsimmodstandappdocker/sample_wwtp_api:v0.1           latest    b02904c251da   33 minutes ago      3.28GB
    ```

7. Run the sflorenz05/depsimmodstandappdocker/sample_wwtp_api:v0.1 microservice image in Docker.

    ```console
    docker run --rm -p 9900:9910 sflorenz05/depsimmodstandappdocker/sample_wwtp_api:v0.1
    ```

8. Once the microservice container is running in Docker, you can check the status of the service by opening the following URL in a web browser:

    ```console
    curl http://localhost:9900/api/health
    ```

    - Expected Output:

    ```console
    {"status:  ok"}
    ```

9. Test the running service:

    ```console
    curl -v -H Content-Type:application/json -d '{"nargout":1,"rhs":[]}' "http://localhost:9900/sample_wwtp/RunScript"
    ```

    - Expected Output:

    ```console
    *   Trying 127.0.0.1...
    * TCP_NODELAY set
    * Connected to localhost (127.0.0.1) port 9900 (#0)
    > POST /sample_wwtp/RunScript HTTP/1.1
    > Host: localhost:9900
    > User-Agent: curl/7.58.0
    > Accept: */*
    > Content-Type:application/json
    > Content-Length: 22
    >
    * upload completely sent off: 22 out of 22 bytes
    < HTTP/1.1 200 OK
    < Content-Type: application/json
    < Content-Length: 2246
    < Connection: Keep-Alive
    <
    {"lhs":[{"mwdata":[0.0011661913712576013,0.0011656552047891113,0.0011651500435576161,0.0011646621214290137,0.0011641501107277756,0.0011636731687118171,0.0011632183530331474,0.0011627483395769197,0.0011623142755476088,0.0011619052266209826,0.0011614885838502095,0.0011611087243227512,0.0011607583999199266,0.0011604095724446005,0.0011600933409281105,0.0011597967240833207,0.0011594980752658594,0.0011592260810681049,0.0011589746578310682,0.0011587241126855682,0.0011585007690086608,0.0011583058246666742,0.0011581246780592658,0.00115797083546392,0.0011578460594748971,0.0011577427494580742,0.0011576633957366069,0.0011576113714618036,0.0011575847859613493,0.0011575738134458583,0.0011575686049660589,0.0011575736542354228,0.0011575804839342723,0.0011575869780676598,0.0011575950107918995,0.0011576116278703072,0.0011576604030943923,0.0011577441726875067,0.0011578482985437769,0.0011580041458839549,0.0011582290494772259,0.0011584862880131353,0.0011588170368502194,0.0011592542314627502,0.0011597135460442388,0.001160213996422082,0.0011608074069071434,0.0011613935974357343,0.0011619798879220567,0.0011626221905090724,0.0011632315876106858,0.0011638163287947482,0.0011644279284504292,0.001164997058672898,0.0011655448922121934,0.001166115311986689,0.0011666481989567508,0.001167161958845388,0.0011676980857126236,0.0011681911463549443,0.0011686444516332602,0.0011690956620014584,0.0011695022229450481,0.001169873843466873,0.0011702374833350826,0.0011705601873169577,0.0011708432142107812,0.0011711074787993277,0.0011713322086181711,0.0011715169399899911,0.0011716732354336765,0.0011717994892195959,0.001171900484897775,0.0011719804701084055,0.0011720409026323973,0.0011720816676807932,0.0011721032963377242,0.0011721096779236527,0.001172094524548635,0.0011720534566531564,0.0011719955204558521,0.0011718977753137707,0.0011717502535832907,0.0011715786665948504,0.0011713560275292878,0.0011710591641339583,0.0011707459002111224,0.0011704006256147998,0.0011699875427812561,0.0011695739555718709,0.0011691448226447973,0.0011686592790298087,0.0011681871148270641,0.0011677124872580826,0.001167192328713625,0.0011666942065969705,0.001166199625408051,0.0011656653651054031,0.0011651569082752966,0.0011646534882622764],"mwsize":[100,1],"mwtype":"double"}]}   
    ```

10. Container log: `sflorenz05/depsimmodstandappdocker/sample_wwtp_api:v0.1`

    ```console
    1 [2023.02.03 17:25:55.631370] [information] Starting Microservice Runner (pid = 1)
    2 [2023.02.03 17:25:55.631476] [information] Global locale: en_US
    3 [2023.02.03 17:25:55.631484] [information] Global encoding: US-ASCII
    4 [2023.02.03 17:25:55.631489] [information] terminal encoding: US-ASCII
    12 [2023.02.03 17:25:55.998795] [information] configuring WebFunction router
    13 [2023.02.03 17:25:55.998835] [information] -- (no routes file configured) Using XHeaderMatcher for WebFunction routing
    79 [2023.02.03 17:25:56.964386] [out] [worker:1] Worker ready - protocol v2
    83 [2023.02.03 17:25:56.964985] [information] [PTR:0x5c0b30] [SERVICE:worker] [THREAD_POOL:request_thread_pool] Worker 1 started [Microservice Runner]
    Accepting HTTP connections on 3ed43635e06b:9910
    101 [2023.02.03 17:25:56.965405] [information] Microservice Runner started
    102 [2023.02.03 17:25:56.965439] [information] [PTR:0x5c0b30] [SERVICE:http] [THREAD_POOL:request_thread_pool] [endpoint:[::]:9910] Listening for connections
    185 [2023.02.03 17:28:31.502410] [out] [worker:1]     0.0012
    186 [2023.02.03 17:28:31.502443] [out] [worker:1]     0.0012
    187 [2023.02.03 17:28:31.502448] [out] [worker:1]     0.0012
    188 [2023.02.03 17:28:31.502452] [out] [worker:1]     0.0012
    189 [2023.02.03 17:28:31.502455] [out] [worker:1]     0.0012
    190 [2023.02.03 17:28:31.502459] [out] [worker:1]     0.0012
    191 [2023.02.03 17:28:31.502462] [out] [worker:1]     0.0012
    192 [2023.02.03 17:28:31.502465] [out] [worker:1]     0.0012
    193 [2023.02.03 17:28:31.502469] [out] [worker:1]     0.0012
    194 [2023.02.03 17:28:31.502472] [out] [worker:1]     0.0012
    195 [2023.02.03 17:28:31.502475] [out] [worker:1]     0.0012
    196 [2023.02.03 17:28:31.502479] [out] [worker:1]     0.0012
    197 [2023.02.03 17:28:31.502485] [out] [worker:1]     0.0012
    198 [2023.02.03 17:28:31.502508] [out] [worker:1]     0.0012
    199 [2023.02.03 17:28:31.502512] [out] [worker:1]     0.0012
    200 [2023.02.03 17:28:31.502517] [out] [worker:1]     0.0012
    201 [2023.02.03 17:28:31.502520] [out] [worker:1]     0.0012
    202 [2023.02.03 17:28:31.502525] [out] [worker:1]     0.0012
    203 [2023.02.03 17:28:31.502529] [out] [worker:1]     0.0012
    204 [2023.02.03 17:28:31.502533] [out] [worker:1]     0.0012
    205 [2023.02.03 17:28:31.502538] [out] [worker:1]     0.0012
    ```
