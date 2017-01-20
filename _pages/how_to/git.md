---
layout: page
title: How to Git
tagline: 
description:
---

# Introduction
This document explains minimum requirements needed for participating to FCCI. A lot of additional features are detailed in the following on the documentation \url{https://git-scm.com/book/fr/v2}. It is assumed here the reader has already a github account.

## FCCI2017 group settings

### Setup to Contribute to the FCCI
This assume that you already have a GitHub account, if you don't please visit
and follow the instruction.

1. **Fork the repository**

    Click on the bouton [ADD IMG] form the https://github.com/fcci2017/FCCI.git, and select
    your account.

    This will create a copy to the fcci repository owned by the fcci organisation,
    allowing you to modify a copy of the fcci repository whitout applying any
    change ont he main repository before your change are ready to be added. 
    
    Whne you believe your improvement idea/suggestion/work are ready to be
    added, you an submit a pull request. A pull request is a change propostion
    that will be reviewed by (all) the other members of the organisation. During
    the review proccess everyone will comment/critic you change proposal allowing
    it to reach a consensual form. Once each comment/critics have been adressed
    through modification or discussion the Pull Request will be merged.
    
    While a Pull Request can be summited by anyone who is willing to contribute, a
    Pull Request can only be merged by an FCCI member. It is not allowed to merge
    your own PR even if you have the authority.

2. **Clone your fork locally**

    On you have forked the fcci repository on your own github account you will be
    able to clone your own fork (copy) of the repository on (each of) your computer.

    ```
    git clone https://github.com/git_username/FCCI.git
    ```

3. **Remote set up**
    
    Once you have clone your repository into your computer, you can add a remote
    (link to the main repository -- the link to you own fork of the repository is
    automatically done when cloning it. -- you can access the list/name of remote
    you have set up by using the `git remote -v` command)

    ```
    cd FCCI
    git remote add upstream https://github.com/fcci2017/FCCI.git
    ```

This will allow you to pull the last version of the repository from the main
repository. Usually the link to the remote are used in only one direction:
  
  - from the main repository to you computer, -- `git rebase upstrean/master`
  - from your computer to you own fork (copy of the repository) -- `git push origin branch`
  - from you own fork -- Pull Request (done on github website)

*more detail instruction are provided in the section below*
*all the folowing instruction supposed that you are located in the repository
folder*


### Branch Gymnastics
Git allow you to have different branches. Each branch can contain different
version of you sources. For example, if you are developing a software, you can
imagine have a `develop` which contain the fastest version of the software
including all the fastest feature, a `master` branch containing the last stable
version, a different branches for each features you are developing.
you can switch between different branch using:
```
git checkout my_branch
```
you can create a new branch using:
```
git checkout -b my_new_branch
```
In this case a new branch will be create from the branch you are in.

Grab a single file from an other branch:
```
git checkout source_branch my_file
```

### Update your computer repository
Before working on some improvement/addition to the project make sure you have
the last version of it locally:

``` sh
git fetch --all # This will download all the information \ 
                # about news commit from all the different remote \
                # you have setted up
git rebase upstream master # add the last commit to your actual branch
```


### Work with your local git clone
Each time you have made a set of modification you can commit those changes. Each
commit corresponds to a all modifications since the last commit, allowing you to
jump back to a certain status of your work. To do a commit, you need first to
add some modified file to the next commit and then commit. To each commit, a
message is associated to allow to inform about the change you have made:
```
 git add my_file1 my_file2...
```

```
git commit -m "my messgae"
```
It is possible if many file have been modified, to commit them together,
separated or grouped as required.

### Working with you fork
As you have done many different modification of your file, which corresponds to
some number, you need to synchronise your cloud clone (fork) of this work:
```
git push remote branch
```
where *remote* correspond to the name you have give to your cloud clone (remote)
-- usually *origin*.

### Submitting you modification to the Organisation repository
To submit a set a change, that you considerer as finalise you have to issue a
Pull Request (PR). TO do it, you need to go on GitHub using your favorite
browser, go into you cloud clone of the repository, switch to the branch and
then click on pull request.
The pull request will be on the Organisation repository from you cloud copy of
the repository. You may want to add some comment to explain you change. Then
your collaborator will review your modification, discuss them, and when every
body get to agree on them they will be merged into the `master` branch of the
organisation repository.

As long as a Pull Request from one of your cloud clone branch is not merge, all
new commits push from you local copy to your cloud copy will be automatically
added to the PR, allowing you to improve you set of modification accordingly to
the ongoing review (that you can follow on you Pull request thread).



