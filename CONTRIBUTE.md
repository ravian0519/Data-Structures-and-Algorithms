# Contributing Guidelines

This documentation contains a set of guidelines to help you during the contribution process.
We are happy to welcome all the contributions from anyone willing to improve/add codes  to this project.

## Submitting Contributions👩‍💻👨‍💻

Below you will find the process and workflow used to review and merge your changes.

## Step 1 : Fork the Project

- Fork this Repository. This will create a Local Copy of this Repository on your Github Profile. Keep a reference to the original project in `upstream` remote.

```bash
git clone https://github.com/<your-username>/Data-Structures-and-Algorithms.git
cd Data-Structures-and-Algorithms
git remote add upstream https://github.com/ravian0519/Data-Structures-and-Algorithms.git
```

- If you have already forked the project, update your copy before working.

```bash
git remote update
git checkout <branch-name>
git rebase upstream/<branch-name>
```

## Step 2 : Branch

Create a new branch. Use its name to identify the issue your addressing.

```bash
# It will create a new branch with name Branch_Name and switch to that branch 
git checkout -b branch_name
```

## Step 3 : Work

- Choose  either Data-Structures folder or Algorithms folder.
- Create language folder(C++/Python) folder if doesn't exists.
- Add your code in the specified language folder.


## Step 3 : add all new files to branch Branch_Name
```bash
git add .
```

## Step 4 : Commit your changes

- To commit give a descriptive message for the convenience of reveiwer by:

```bash
git commit -m "message"
```

- **NOTE**: A PR should have only one commit. Multiple commits should be squashed.

## Step 6 : push your work to your remote repository

```bash
git push -u origin Branch_Name
```

## Step 7 : Pull Request

- Go to your repository in browser and click on compare and pull requests. Then add a title and description to your pull request that explains your contribution.

- Voila! Your Pull Request has been submitted and will be reviewed by the moderators and merged.🥳

## Tip

It always takes time to understand and learn. So, do not worry at all. We know **you have got this**!💪
