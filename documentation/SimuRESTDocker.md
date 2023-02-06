# Create Microservice Docker Image

1. Clone the repository: `git clone https://github.com/sfl0r3nz05/DepSimModStandAppDocker.git`
2. Go into the project folder `cd ~/DistributedBchFWArchIoT/src/simple_simulink_proj` using Matlab:

   <img width="960" alt="dockerdep4" src="https://user-images.githubusercontent.com/6643905/216972286-c134e690-52ab-4d52-8d46-0d60566b156e.png">

  > **Note:** Pre-requisite:
  >> It is required that the model has been previously deployed in a container.
  >> It is recommended that you have previously followed the instructions [to build the model in the Docker container](./SimuDockerDep.md).

3. Create Deployable Archive

   - Creates a deployable archive with options specified

    ```console
    opts = compiler.build.ProductionServerArchiveOptions('RunScript.m',...
    'ArchiveName','simple_simulink_proj',...
    'AutoDetectDataFiles','on',...
    'Verbose','on')
    ```

    - Expected Output:

    ```console
    opts = 

    ProductionServerArchiveOptions with properties:

              ArchiveName: 'simple_simulink_proj'
           FunctionFiles: {'/home/usuario/DepSimModStandAppDocker/src/simple_simulink_proj/RunScript.m'}
       FunctionSignatures: ''
          AdditionalFiles: {}
      AutoDetectDataFiles: on
          SupportPackages: {'autodetect'}
                  Verbose: on
                OutputDir: './simple_simulink_projproductionServerArchive'
    ```

   - Package the `RunScript` function into a deployable archive using the [compiler.build.productionServerArchive](https://es.mathworks.com/help/compiler_sdk/mps_dev_test/compiler.build.productionserverarchive.html) function.

    ```console
    mpsResults=compiler.build.productionServerArchive(opts)
    ```

    - Expected Output:

    ```console
    mcc -W CTF:simple_simulink_proj -d ./simple_simulink_projproductionServerArchive -v -Z autodetect -U /home/usuario/DepSimModStandAppDocker/src/simple_simulink_proj/RunScript.m
    Compiler version: 8.4 (R2022a)
    Analyzing file dependencies. 
    ### Generating code and artifacts to 'Model specific' folder structure
    ### Generating code into build folder: /home/usuario/DepSimModStandAppDocker/src/simple_simulink_proj/slprj/raccel_deploy/Modelo_Simulink_2021b
    ### Building the rapid accelerator target for model: Modelo_Simulink_2021b
    ### Invoking Target Language Compiler on Modelo_Simulink_2021b.rtw
    ### Using System Target File: /home/usuario/MATLAB/rtw/c/raccel/raccel.tlc

    Build Summary

    Top model rapid accelerator targets built:

    Model                  Action                       Rebuild Reason                                    
    ======================================================================================================
    Modelo_Simulink_2021b  Code generated and compiled  Code generation information file does not exist.  

    1 of 1 models built (0 models already up to date)
    Build duration: 0h 0m 4.2823s
    Parsing file "/home/usuario/DepSimModStandAppDocker/src/simple_simulink_proj/RunScript.m"
            (referenced from command line).
    Generating file "/home/usuario/DepSimModStandAppDocker/src/simple_simulink_proj/simple_simulink_projproductionServerArchive/readme.txt".

    mpsResults = 

      Results with properties:

                      BuildType: 'productionServerArchive'
                          Files: {'/home/usuario/DepSimModStandAppDocker/src/simple_simulink_proj/simple_simulink_projproductionServerArchive/simple_simulink_proj.ctf'}
       IncludedSupportPackages: {}
                       Options: [1×1 compiler.build.ProductionServerArchiveOptions]
    ```

    - The compiler.build.Results object mpsResults contains information on the build type, generated files, included support packages, and build options.
    - Once the build is complete, the function creates a folder named `simple_simulink_projproductionServerArchive` in your current directory to store the deployable archive.
      - *See the compilation image*

        |<img width="652" alt="dockerdep4" src="https://user-images.githubusercontent.com/6643905/216991691-08b0d862-fe69-414d-a4e3-482d2e8bd8ab.png">|
        |:------------------------------------:|

4. Package Archive into Microservice Docker Image

   - Build the microservice Docker image using the mpsResults object that you created.
   - You can specify additional options in the compiler.build command by using name-value arguments.

    ```console
    compiler.package.microserviceDockerImage(mpsResults,'ImageName','sflorenz05/depsimmodstandappdocker/simple_simulink_proj_api:v0.1')
    ```

    - Expected Output:

    ```console
    DOCKER CONTEXT LOCATION:

    /home/usuario/DepSimModStandAppDocker/src/simple_simulink_proj/sflorenz05/depsimmodstandappdocker/simple_simulink_proj_api:v0.1microserviceDockerImage


    FOR HELP GETTING STARTED WITH MICROSERVICE IMAGES, PLEASE READ:

    /home/usuario/DepSimModStandAppDocker/src/simple_simulink_proj/sflorenz05/depsimmodstandappdocker/simple_simulink_proj_api:v0.1microserviceDockerImage/GettingStarted.txt
    ```

5. The function generates the following files within a folder named micro-magicmicroserviceDockerImage in your current working directory:

   1. `sflorenz05/depsimmodstandappdocker/simple_simulink_proj_api:v0.1microserviceDockerImage/applicationFilesForMATLABCompiler/sample_wwtp.ctf` — Deployable archive file.
   2. `Dockerfile` — Docker file that specifies Docker run-time options.
   3. `GettingStarted.txt` — Text file that contains deployment information.
      - *See the packaging image*

          |<img width="724" alt="dockerdep4" src="https://user-images.githubusercontent.com/6643905/217005316-5728b490-6e39-45ca-9192-42aa190cce54.png">|
          |:----------------------------------------:|

6. Test the image:

    ```console
    docker images -a
    ```

    - Expected Output:

    ```console
    REPOSITORY                                                    TAG       IMAGE ID       CREATED          SIZE
    sflorenz05/depsimmodstandappdocker/simple_simulink_proj_api   v0.1      8d40abeea823   5 minutes ago    3.26GB
    ```

7. Run the sflorenz05/depsimmodstandappdocker/sample_wwtp_api:v0.1 microservice image in Docker.

    ```console
    docker run --rm -d -p 9900:9910 sflorenz05/depsimmodstandappdocker/simple_simulink_proj_api:v0.1
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
    curl -v -H Content-Type:application/json -d '{"nargout":1,"rhs":[]}' "http://localhost:9900/simple_simulink_proj/RunScript"
    ```

    - Expected Output:

    ```console
    *   Trying 127.0.0.1...
    * TCP_NODELAY set
    * Connected to localhost (127.0.0.1) port 9900 (#0)
    > POST /simple_simulink_proj/RunScript HTTP/1.1
    > Host: localhost:9900
    > User-Agent: curl/7.58.0
    > Accept: */*
    > Content-Type:application/json
    > Content-Length: 22
    >
    * upload completely sent off: 22 out of 22 bytes
    < HTTP/1.1 200 OK
    < Content-Type: application/json
    < Content-Length: 5975
    < Connection: Keep-Alive
    <
    {"lhs":[{"mwdata":[0,0.01,0.02,0.030000000000000002,0.04,0.05,0.060000000000000005,0.07,0.08,0.090000000000000011,0.1,0.11,0.12000000000000001,0.13,0.14,0.15,0.16,0.17,0.18000000000000002,0.19,0.2,0.21000000000000002,0.22,0.23,0.24000000000000002,0.25,0.26,0.27,0.28,0.29000000000000004,0.3,0.31,0.32,0.33,0.34,0.35000000000000003,0.36000000000000004,0.37,0.38,0.39,0.4,0.41000000000000003,0.42000000000000004,0.43,0.44,0.45,0.46,0.47000000000000003,0.48000000000000004,0.49000000000000005,0.5,0.51,0.52,0.53,0.54,0.55,0.56,0.57000000000000006,0.58000000000000007,0.59000000000000008,0.6,0.61,0.62,0.63,0.64,0.65,0.66,0.67,0.68,0.69000000000000006,0.70000000000000007,0.71000000000000008,0.72000000000000008,0.73,0.74,0.75,0.76,0.77,0.78,0.79,0.8,0.81,0.82000000000000006,0.83000000000000007,0.84000000000000008,0.85000000000000009,0.86,0.87,0.88,0.89,0.9,0.91,0.92,0.93,0.94000000000000006,0.95000000000000007,0.96000000000000008,0.97000000000000008,0.98000000000000009,0.9900000000000001,1,1.01,1.02,1.03,1.04,1.05,1.06,1.07,1.08,1.09,1.1,1.11,1.12,1.1300000000000001,1.1400000000000001,1.1500000000000001,1.1600000000000001,1.1700000000000002,1.1800000000000002,1.19,1.2,1.21,1.22,1.23,1.24,1.25,1.26,1.27,1.28,1.29,1.3,1.31,1.32,1.33,1.34,1.35,1.36,1.37,1.3800000000000001,1.3900000000000001,1.4000000000000001,1.4100000000000001,1.4200000000000002,1.4300000000000002,1.4400000000000002,1.4500000000000002,1.46,1.47,1.48,1.49,1.5,1.51,1.52,1.53,1.54,1.55,1.56,1.57,1.58,1.59,1.6,1.61,1.62,1.6300000000000001,1.6400000000000001,1.6500000000000001,1.6600000000000001,1.6700000000000002,1.6800000000000002,1.6900000000000002,1.7000000000000002,1.7100000000000002,1.72,1.73,1.74,1.75,1.76,1.77,1.78,1.79,1.8,1.81,1.82,1.83,1.84,1.85,1.86,1.87,1.8800000000000001,1.8900000000000001,1.9000000000000001,1.9100000000000001,1.9200000000000002,1.9300000000000002,1.9400000000000002,1.9500000000000002,1.9600000000000002,1.9700000000000002,1.9800000000000002,1.99,2,0,0.0039998930497837969,0.014638517821577591,0.030157393053285568,0.049126714893450107,0.070391971371001935,0.093028568734232472,0.11630332932765945,0.13964187665854044,0.16260105863012933,0.18484567724634041,0.2061288947485,0.22627577416263303,0.24516948839159514,0.26273979783140788,0.2789534533789928,0.29380623080987478,0.307316344868637,0.31951902792879316,0.33046208952330491,0.34020230010190877,0.34880246562794326,0.35632907959945015,0.36285045621347267,0.36843526307637292,0.37315138443306123,0.37706505663595313,0.38024022675306635,0.38273809304284,0.38461679269045662,0.38593120787050911,0.38673286601533724,0.38706991424952508,0.3869871514043729,0.38652610394253206,0.38572513458080021,0.3846195744656416,0.38324187148936439,0.38162174878475874,0.3797863686451608,0.37776049812191953,0.37556667338354183,0.37322536060710171,0.3707551117358307,0.36817271389664058,0.36549333164435371,0.362730641499788,0.35989695848861653,0.35700335457727239,0.35405976904978781,0.35107511098259725,0.348057354059176,0.345013624028131,0.34195027915130077,0.338872984016265,0.3357867771033915,0.33269613250371882,0.32960501618267934,0.32651693717761959,0.32343499410571996,0.320361917344402,0.31730010722958069,0.31425166859894121,0.31121844198840692,0.30820203177058203,0.30520383150460317,0.30222504674779188,0.29926671556098139,0.29632972692158316,0.29341483724143669,0.290522685170361,0.28765380485112357,0.28480863777728255,0.28198754339205062,0.27919080855396033,0.27641865598363585,0.273671251795401,0.27094871220769479,0.26825110951731468,0.26557847741430457,0.2629308157068031,0.2603080945183236,0.25771025801370379,0.25513722770430514,0.252588905377892,0.25006517569396364,0.24756590848110357,0.2450909607690876,0.24264017858506706,0.24021339854003557,0.23781044922899935,0.23543115246576155,0.23307532437097961,0.23074277633012072,0.22843331583613805,0.22614674723005315,0.22388287235118307,0.22164149110744344,0.21942240197499532,0.21722540243547223,0.21505028935808496,0.212896859333087,0.21076490896234004,0.20865423511206554,0.20656463513228468,0.20449590704693343,0.20244784971817223,0.20042026298800777,0.19841294779997523,0.19642570630331344,0.19445834194177011,0.19251065952893504,0.1905824653117599,0.18867356702374011,0.18678377392904483,0.18491289685873749,0.18306074824008639,0.18122714211984331,0.17941189418226738,0.17761482176256882,0.17583574385637371,0.17407448112572757,0.17233085590210018,0.17060469218679222,0.16889581564909584,0.16720405362251695,0.16552923509932832,0.16387119072369238,0.16222975278355467,0.16060475520149189,0.15899603352466976,0.15740342491404713,0.15582676813294682,0.15426590353509625,0.15272067305222783,0.15119092018131911,0.14967648997153812,0.14817722901095667,0.14669298541307979,0.14522360880323776,0.14376895030487682,0.14232886252578497,0.14090319954427791,0.13949181689537249,0.13809457155696717,0.13671132193604815,0.13534192785493637,0.13398625053758945,0.13264415259596904,0.13131549801648232,0.13000015214650804,0.12869798168101157,0.12740885464925555,0.12613264040161076,0.12486920959647139,0.12361843418727672,0.12238018740964342,0.12115434376860823,0.11994077902598517,0.11873937018783608,0.11754999549205615,0.11637253439607578,0.11520686756467684,0.11405287685792698,0.112910445319227,0.11177945716347533,0.11065979776534689,0.10955135364768649,0.10845401247001601,0.10736766301715477,0.1062921951879513,0.10522749998412871,0.10417346949923866,0.10312999690772613,0.10209697645410258,0.10107430344222768,0.10006187422469742,0.099059586192338261,0.098067337763806772,0.09708502837529237,0.096112558470324266,0.09514982948967958,0.094196743861392651,0.093253204990864938,0.092319117251073363,0.091394385972877232,0.090478917435422,0.089572618856639752,0.088675398383843723,0.08778716508441857,0.086907828936602954,0.0860373008203651,0.085175492508369033,0.08432231665703252,0.083477686797673714,0.082641517327746841,0.0818137235021659,0.0809942214247148,0.08018292803954441,0.07937976112275405,0.078584639274057858],"mwsize":[201,2],"mwtype":"double"}]}
    ```

10. Container log: `sflorenz05/depsimmodstandappdocker/sample_wwtp_api:v0.1`

    ```console
    docker run --rm -p 9900:9910 sflorenz05/depsimmodstandappdocker/simple_simulink_proj_api:v0.1
    ```

    - Output:

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
