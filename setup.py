from setuptools import setup, Extension

ext_modules = [
    Extension(
        "vertez",
        ["firefly.cpp"],
        include_dirs=["Infernix"],
        language="c++"
    )
]

setup(
    name="vertez",
    version="0.1",
    ext_modules=ext_modules,
    install_requires=["pybind11"]
)