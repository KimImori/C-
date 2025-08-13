#! /bin/bash

sudo apt update
sudo apt install -y python3-tk python3-pyqt5 x11-apps mesa-utils

python3 -m venv .venv
source .venv/bin/activate

python -m pip install --upgrade pip
pip install -r requirements.txt

python plot_csv.py ./data.csv --title "Benchmark" --x-label "N - разер данных" --y-label "Время исполнения в секундах"