FROM matlabruntime/r2022a/release/update6/e0000000000000200
COPY ./applicationFilesForMATLABCompiler /usr/bin/mlrtapp
RUN chmod -R a+rX /usr/bin/mlrtapp/*
RUN useradd -ms /bin/bash appuser
USER appuser
ENTRYPOINT ["/usr/bin/mlrtapp/RunSim"]
