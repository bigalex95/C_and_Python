from setuptools import Extension, setup

module = Extension("demo",
                  sources=[
                    'demolib.c',
                    'demomodule.c'
                  ])
setup(name='demo',
     version='1.0',
     description='Python wrapper for custom C extension',
     ext_modules=[module])