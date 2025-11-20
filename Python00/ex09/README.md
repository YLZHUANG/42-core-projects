# ft_package

A sample Python package.

---

## Installation

```bash
pip3 install build   # install the build tool if not already
python3 -m pip install --upgrade pip setuptools wheel build  # if needed

python3 -m build

pip3 install ./dist/ft_package-0.0.1.tar.gz
# or
pip3 install ./dist/ft_package-0.0.1-py3-none-any.whl

## Verify with pip show
pip3 show -v ft_package

# Uninstall
pip3 uninstall ft_package
rm -rf build dist *.egg-info

## Test
from ft_package import count_in_list
print(count_in_list(["toto", "tata", "toto"], "toto"))  # 2
print(count_in_list(["toto", "tata", "toto"], "tutu"))  # 0