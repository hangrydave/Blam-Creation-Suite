import os
import subprocess
import build_task_manager
import util

class ExtractBuildTask(build_task_manager.BuildTask):
    def __init__(self, filepath : str, output : str, _parent_tasks = [], force = False):
        super().__init__(f'ExtractBuildTask', _parent_tasks)
        self.filepath = filepath
        self.output = output
        self.force = force

    def build(self):
        if not self.force and os.path.exists(self.output):
            return # Don't extract
        
        _7z_path = os.path.join(os.environ['_7Z_DIR'], '7z')
        
        destination_directory = os.path.dirname(self.filepath)
        
        if not os.path.exists(destination_directory):
            os.makedirs(destination_directory)
        
        print(_7z_path)
        process = subprocess.Popen([_7z_path, 'x', '-y', self.filepath, f'-o{self.output}'])
        process.wait()

class ExtractMSIBuildTask(build_task_manager.BuildTask):
    def __init__(self, filepath : str, output : str, _parent_tasks = [], force = False):
        super().__init__(f'ExtractMSIBuildTask', _parent_tasks)
        self.filepath = filepath
        self.output = output
        self.force = force

    def build(self):
        if not self.force and os.path.exists(self.output):
            return # Don't extract
        
        destination_directory = self.output
        
        if not os.path.exists(destination_directory):
            os.makedirs(destination_directory)

        destination_directory = destination_directory.replace('/', '\\')
        
        process = subprocess.Popen(['msiexec', '/a', self.filepath, '/qn', f'TARGETDIR={destination_directory}'])
        process.wait()

class ExtractTarfileBuildTask(build_task_manager.BuildTask):
    def __init__(self, filepath : str, output : str, _parent_tasks = [], force = False):
        super().__init__(f'ExtractTarfileBuildTask', _parent_tasks)
        self.filepath = filepath
        self.output = output
        self.force = force

    def build(self):
        if not self.force and os.path.exists(self.output):
            return # Don't extract
        
        _7z_path = os.path.join(os.environ['_7Z_DIR'], '7z')
        
        destination_directory = self.output
        
        if not os.path.exists(destination_directory):
            os.makedirs(destination_directory)

        destination_directory = destination_directory.replace('/', '\\')
        
        command1 = [_7z_path, 'x', '-y', self.filepath, '-aoa', '-so']
        command2 = [_7z_path, 'x', '-y', '-aos', '-si', '-ttar', f'-o{self.output}']

        process1 = subprocess.Popen(command1, stdout=subprocess.PIPE)
        process2 = subprocess.Popen(command2, stdin=process1.stdout)

        process1.wait()
        process2.wait()

        process1.stdout.close()