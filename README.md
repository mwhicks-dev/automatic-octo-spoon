# automatic-octo-spoon: Real-time options information

This application provides a small, single-threaded server used to routinely obtain stock information.

## Table of Contents

* Introduction
* Usage
* License
* Acknowledgement

## Introduction

automatic-octo-spoon is the first step in a larger distributed system used for quantitative trading over C++. The application structure allows the composition of any particular data source and network adapter required by a user, and uses them in order to provide both routine querying of selected options as well as on-demand requests for time series/intervals.

## Usage

Right now, this repository is only usable in the sense that tests can be run on it. You can build the tests via Docker using:

```bash
docker build --no-cache -t opt ${GITHUB_WORKSPACE}/
```

where `GITHUB_WORKSPACE` is the path to `automatic-octo-spoon` (inclusive), and you can run all of the tests currently available using:

```bash
docker run --rm -t --entrypoint "./standard_time_test" opt
docker run --rm -t --entrypoint "./symbol_test" opt
docker run --rm -t --entrypoint "./ticker_test" opt
docker run --rm -t --entrypoint "./time_series_test" opt
docker run --rm -t --entrypoint "./ticker_data_test" opt
docker run --rm -t --entrypoint "./ticker_queue_test" opt
```

## License

MIT License. See `LICENSE`.

## Acknowledgements

* [READMINE](https://github.com/mhucka/readmine) for README structure
