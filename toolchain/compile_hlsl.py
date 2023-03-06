import os
import sys
sys.path.append(os.path.realpath(os.path.dirname(__file__))) # Allow Local Imports
import util
import subprocess
import shlex

directxshadercompiler_directory = os.path.join(util.bcs_third_party_dir, 'directxshadercompiler/directxshadercompiler')
dxc = os.path.join(directxshadercompiler_directory, 'bin/dxc')

inputs = util.command_line['inputs']
sources = util.command_line['sources']
outputs = util.command_line['outputs']
target_gen_dir = util.command_line['target_gen_dir']
root_gen_dir = util.command_line['root_gen_dir']
root_build_dir = util.command_line['root_build_dir']
dxc_passthrough = util.command_line['dxc_passthrough']

print(target_gen_dir)
print(root_gen_dir)
print(root_build_dir)
print(len(inputs), len(sources))
print(outputs)

for index, input in enumerate(inputs):
    source = sources[index]
    output = os.path.join(root_gen_dir, source)

    output_directory : str = os.path.join(os.path.dirname(output), "CompiledShaders")
    file_name, file_extension = os.path.splitext(os.path.basename(output))

    if not file_extension.lower() == ".hlsl":
        continue

    output_filepath = os.path.join(output_directory, file_name + ".h")

    if not os.path.exists(output_directory):
        os.makedirs(output_directory)
    
    #with open(output_filepath, "w") as file:
    #    file.write("#pragma once")

    arguments = shlex.split(dxc_passthrough)
    command = [dxc, input, '-Fh', output_filepath, '-Vn', f'g_p{file_name}'] + arguments
    process = subprocess.Popen(command)
    process.wait()




    #

for input_file in inputs:
    #process = subprocess.Popen([dxc, "-T", "cs_6_2", input_file, '-Fo'])
    #process.wait()
    #print(input_file)
    break
