#!/usr/bin/env python3
"""
Utility to plot a graph from a CSV file with two numeric columns: X,Y.

Supports auto delimiter detection and optional header skipping.
"""

import argparse
import csv
from pathlib import Path
from typing import List, Tuple, Optional

import matplotlib as mpl
import matplotlib.pyplot as plt


def detect_delimiter(sample: str) -> str:
    possible_delimiters = [",", ";", "\t", " "]
    counts = {d: sample.count(d) for d in possible_delimiters}
    best = max(counts, key=counts.get)
    return best if counts[best] > 0 else ","


def read_xy_pairs(path: str, delimiter: Optional[str], has_header: bool) -> Tuple[List[float], List[float]]:
    with open(path, "r", encoding="utf-8") as f:
        sample = f.read(4096)
        f.seek(0)
        effective_delimiter = detect_delimiter(sample) if delimiter in (None, "auto") else delimiter
        reader = csv.reader(f, delimiter=effective_delimiter)

        if has_header:
            next(reader, None)

        x_values: List[float] = []
        y_values: List[float] = []
        for row in reader:
            if not row or len(row) < 2:
                continue
            try:
                x = float(row[0].strip())
                y = float(row[1].strip())
            except ValueError:
                continue
            x_values.append(x)
            y_values.append(y)
        return x_values, y_values


def main() -> None:
    parser = argparse.ArgumentParser(description="Plot a graph from CSV with two columns: X,Y")
    parser.add_argument("input", help="Path to CSV file, e.g. data.csv")
    parser.add_argument("--delimiter", default="auto", help="Delimiter: auto , ; \t ' '")
    parser.add_argument("--has-header", action="store_true", help="Indicates first row is a header")
    parser.add_argument("--plot-type", choices=["line", "scatter"], default="line", help="Plot type")
    parser.add_argument("--title", default="", help="Plot title")
    parser.add_argument("--x-label", default="X", help="X axis label")
    parser.add_argument("--y-label", default="Y", help="Y axis label")
    parser.add_argument("--output", default="", help="Output image path, e.g. out.png. If empty, show window")
    parser.add_argument("--dpi", type=int, default=120, help="DPI for saved image")

    args = parser.parse_args()

    x_values, y_values = read_xy_pairs(args.input, args.delimiter, args.has_header)

    plt.figure(figsize=(8, 5))
    if args.plot_type == "line":
        plt.plot(x_values, y_values, "-o", linewidth=2, markersize=4)
    else:
        plt.scatter(x_values, y_values, s=20)

    plt.title(args.title)
    plt.xlabel(args.x_label)
    plt.ylabel(args.y_label)
    plt.grid(True, linestyle="--", alpha=0.5)

    plt.tight_layout()

    backend = mpl.get_backend().lower()
    is_non_interactive_backend = (
        backend in {"agg", "pdf", "svg", "ps", "cairo"} or "inline" in backend
    )

    output_path = args.output
    if not output_path and is_non_interactive_backend:
        # Auto-save when running in a headless/non-interactive backend
        output_path = str(Path(args.input).with_suffix(".png"))

    if output_path:
        plt.savefig(output_path, dpi=args.dpi)
        print(f"Saved: {output_path}")
    else:
        plt.show()


if __name__ == "__main__":
    main()


