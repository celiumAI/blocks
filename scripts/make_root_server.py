# %%
# i load the scripts from docs/scripts.
# in this case i will load async_server.md
# then i will extract the code from the markdown file which is simple because it is a single cpp code block that is simple to extract with just regex
# then i will use this script to apply simple string manipulations to it
# the first one is to replace comments that follow the pattern "// /docs/.*.md" with the actual code from the file
# i.e. have a recursive function that replaces the comments with the code from the file
# then i will use this script to flash the cpp code to the esp8266 d1 mini using esptool
# %%
def get_code_block(docs_path: str, language: str = 'cpp'):
    import re
    arduino_doc = open(docs_path, 'r').read()
    code_block = re.findall(rf'```{language}(.+?)```', arduino_doc, re.DOTALL)[0]

    lines_to_replace = []
    code_blocks = []
    for line in code_block.split('\n'):
        if re.match(r'.*// /docs/.*.md.*', line):
            print(line)
            doc_path = base_dir + line.split('// /')[1]
            lines_to_replace.append(line)
            code_blocks.append(get_code_block(doc_path, language))
    
    for line, code in zip(lines_to_replace, code_blocks):
        print(line)
        code_block = code_block.replace(line, code)
    return code_block
# %%
base_dir = "/home/mcfrank/celium-experiments/product_demos/blocks/"
doc_path = base_dir + "docs/async_root_server.md"
print(doc_path)

raw_script = get_code_block(doc_path)

print(raw_script)

# %%
import time

timestamp = int(time.time())*1000

stamped_script = raw_script.replace("REPLACEME", str(timestamp))

print(stamped_script)

# %%