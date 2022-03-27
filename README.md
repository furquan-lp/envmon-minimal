# envmon-minimal

Minimal version of the environment monitor, intended to be used by other applications as a backend. Outputs raw data in a JSON format from the sensors to the hardcoded mDNS URL.

## How does it work?

It exposes a REST-style JSON API to the hardcoded mDNS URL (`http://envmon.local/`) and the data is updated instantly (accounting for all the delays in the backend code itself) as soon as the page is updated.

## How is it intended to be used?

It is intended to be used by a frontend interface through the exposed REST API. There are no API limits but internally the code should be self-delayed by a few hundred milliseconds.

## What JSON data is to be expected?
**Sample JSON format**:
```
[
  {
    "backend": {
      "name": "envmon-minimal",
      "version": "1.3J"
    },
    "envdata": {
      "temp": "33.10",
      "humidity": "39.30"
    },
    "uptime": {
      "hours": "00",
      "minutes": "02",
      "seconds": "43"
    }
  }
]
```
