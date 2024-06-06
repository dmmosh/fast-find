# FAST FIND #

An optimized search CLI tool designed to find files quicker. Designed for working in the terminal for people impatient with Linux's `find` capabilities. Finds all results, sorts in alphabetical order, and allows you to change directory into one of them with lightning speed.

## Usage: ##
```
Usage: ff [options...] search terms...
Options:
  -l, --loose       Loose search. Displays all results with anything remotely like the search term.
  -m, --medium      Medium search. Displays specific results with diregard for file suffix. Default option.
  -s, --strict      Strict search. Displays only results with exact full name.
  -pwd, --print-dir Print full directory of all results. Can be turned on/off.
  -cd, --change-dir Change directory message. By default turned on. Can be turned on/off.
```

## Releases: ##
[LATEST RELEASE](https://github.com/dmmosh/fast-find/releases/tag/v1.0)

## Manual compiling: ##
```
g++ -std=c++20 src/main.cc src/utils.cc -o ./fast-find_/exec;
```

## Cool photos: ##
![2024-04-12_16-54](https://github.com/dmmosh/fast-find/assets/119987092/2c5d9775-7e1f-4e37-b01d-51aadcec386b)
![2024-04-12_16-56](https://github.com/dmmosh/fast-find/assets/119987092/d9e015f1-c684-46a4-8558-9a2d3103da3e)
![2024-04-12_16-59](https://github.com/dmmosh/fast-find/assets/119987092/3cfa0998-9f10-4b2c-b771-a9871b97dbf1)
![2024-04-12_17-03](https://github.com/dmmosh/fast-find/assets/119987092/23fa1ab8-a760-44e5-8a43-365802962bb6)
![2024-04-12_16-53](https://github.com/dmmosh/fast-find/assets/119987092/34ee7886-ecda-4e3c-ba96-80c9b0a8af5c)

## Performance: ##
![2024-04-12_17-02](https://github.com/dmmosh/fast-find/assets/119987092/fda38fdd-16d8-432b-95f0-7ecadd2465e3)
![2024-04-12_17-02_1](https://github.com/dmmosh/fast-find/assets/119987092/2e628ab9-98bd-4d50-a9f5-8302e01afd81)

