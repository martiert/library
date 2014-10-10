#!/usr/bin/env python3
import subprocess
import argparse
import os
import sys
import glob
import shutil

class cmake_builder:
    def __init__(self, args):
        self.args = args
        self.set_environment(args)
        self.create_output_directory(args.build_dir)
        self.set_config_cmd(args)
        self.set_build_cmd(args)
        self.set_test_arguments(args)
        self.compiler = 'cc'

    def run(self):
        if self.args.clean:
            os.chdir('..')
            shutil.rmtree(self.args.build_dir)
            return

        self.clean_if_necessary()
        self.configure()
        self.build()
        if self.args.run_tests:
            self.run_tests()

    def configure(self):
        if not subprocess.call(self.config_cmd) == 0:
            print('Configure failed')
            sys.exit(1)

    def build(self):
        if not subprocess.call(self.build_cmd) == 0:
            print('Build failed')
            sys.exit(1)

    def run_tests(self):
        for test in glob.glob('./bin/*Tests'):
            print('Running test: %s' %test)
            test_cmd = self.create_run_test_command_for(test)
            if subprocess.call(test_cmd) != 0:
                sys.exit(1)

    def set_config_cmd(self, args):
        self.config_cmd = ['cmake', '-DC++11=ON']
        if not self.args.tests:
            self.config_cmd.append('-DMAKE_TESTS=OFF')
        self.config_cmd.append(self.source_directory)

    def set_build_cmd(self, args):
        self.build_cmd = ['make', '-j', str(args.N)]
        if args.verbose:
            self.build_cmd.append('VERBOSE=1')

    def create_output_directory(self, directory):
        self.source_directory = os.path.abspath(os.path.dirname(__file__))
        if not os.path.isdir(directory):
            os.makedirs(directory)
        os.chdir(directory)

    def set_environment(self, args):
        if args.use_clang:
            os.putenv('CC', 'clang')
            os.putenv('CXX', 'clang++')

    def set_test_arguments(self, args):
        self.test_output = ['-o', args.format]

    def clean_if_necessary(self):
        if self.args.rebuild:
            self.clean_directory(os.getcwd())

    def clean_directory(self, directory):
        for delete in glob.glob('%s/*' %directory):
            if os.path.isfile(delete):
                os.remove(delete)
            else:
                shutil.rmtree(delete)

    def create_run_test_command_for(self, test):
        command = []
        if self.args.run_valgrind:
            command.append('valgrind')
        command.append(test)
        for arg in self.test_output:
            command.append(arg)
        return command

def get_arguments():
    parser = argparse.ArgumentParser(description='Build FlyingSquirrel')
    parser.add_argument('--output', '-o', dest='format', default='normal',
                        choices=['normal','junit'], help='Output format from tests')
    parser.add_argument('-j', dest='N', type=int, default=1,
                        help='Number of threads sent to make')
    parser.add_argument('--clang', dest='use_clang', default=False, action='store_true',
                        help='Use clang as compiler')
    parser.add_argument('--build-dir', '-d', dest='build_dir', default='_build_',
                        help='Build output directory')
    parser.add_argument('--verbose', '-V', dest='verbose', action='store_true', default=False)
    parser.add_argument('--rebuild', '-r', dest='rebuild', action='store_true', default=False)
    parser.add_argument('--clean', '-c', dest='clean', action='store_true', default=False)
    parser.add_argument('--valgrind', dest='run_valgrind', action='store_true', default=False)
    parser.add_argument('--no-run-tests', dest='run_tests', action='store_false', default=True)
    parser.add_argument('--no-tests', dest='tests', action='store_false', default=True)
    return parser.parse_args()

if __name__ == '__main__':
    args = get_arguments()

    builder = cmake_builder(args)
    builder.run()
