from setuptools import setup, Extension

ext_modules = [
    Extension(
        "vertezml",
        ["vertezml.cpp"],
        include_dirs=["Infernix"],
        language="c++"
    )
]

setup(
    name="vertezml",
    author="Ravinthiran Partheepan",
    description="Vertez: Statify and Infer",
    long_description='''Vertez is a cutting-edge open-source framework company dedicated to developing powerful and versatile libraries for statistical analysis, machine learning, and deep learning. We empower data scientists, researchers, and developers with a comprehensive suite of tools to drive insights and innovations in diverse domains. At Vertez, we believe in democratizing access to advanced statistical techniques and the latest advancements in artificial intelligence. Our libraries provide an intuitive and flexible platform for statistical modeling, predictive analytics, and complex data-driven decision making. With a focus on simplicity, performance, and scalability, we enable practitioners to efficiently explore, analyze, and infer from their data.''',
    version="0.0.8",
    ext_modules=ext_modules,
    install_requires=["pybind11", "wheel"]
)