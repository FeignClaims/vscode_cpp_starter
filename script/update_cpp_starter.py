#!/usr/bin/env python3
import git
import tarfile
import shutil

reponame = 'cpp_starter'

# Clone the Git repository
repo = git.Repo.clone_from(
    f'https://gitee.com/FeignClaims/{reponame}.git', f'{reponame}')

# Create a tar archive while excluding the .git folder
with tarfile.open(f'{reponame}.zip', 'w:gz') as tar:
    tar.add(f'{reponame}', arcname=f'{reponame}',
            filter=lambda x: None if '.git' in x.name else x)

# Remove the local repository directory
shutil.rmtree(f'{reponame}')
