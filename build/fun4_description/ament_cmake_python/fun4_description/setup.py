from setuptools import find_packages
from setuptools import setup

setup(
    name='fun4_description',
    version='0.0.0',
    packages=find_packages(
        include=('fun4_description', 'fun4_description.*')),
)
