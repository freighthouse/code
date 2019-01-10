# Test commit.

# Tooling

This contains the front-end compiling tools needed for this site.

## Installation
Before proceeding with the installation, it is recommended that you use [nvm](https://github.com/creationix/nvm) to help ensure everyone on the project is using a consistent version of node.js.

1. If you don't have nvm installed, follow these [instructions](https://github.com/creationix/nvm#install-script). Windows users may need to use [nvm-windows](https://github.com/coreybutler/nvm-windows) instead.
1. `nvm install` This will install the version of Node that's defined in `.nvmrc`
1. `nvm use` This will set the correct version of node.js by checking this project's `.nvmrc` file.
1. `npm install --global yarn` Yarn is a package manager built on top of npm. It's faster than npm and helps ensure each developer is using the same package versions when developing this project. For [Homebrew](http://brew.sh/) users, `brew install yarn` also is an option.
1. `yarn` This installs all the correct packages for this project.

*note: nvm and yarn should be the only global dependencies needed for this project*


## Usage
At the beginning of each development session, it's recommended to run `nvm use` to ensure you are developing with the correct version of node.

```
nvm use
```


### Development
To compile CSS and JS run the following command.

```
npm run dev
```

To automatically watch CSS and JS source files for changes and compile, run:

```
npm run dev -- --watch
```

To cancel the watch process, type `Ctrl+c`


### CSS
To compile CSS run the following command.

```
npm run css
```

To automatically compile CSS when files are changed, run:

```
npm run css -- --watch
```


### JS
To compile JS run the following command.

```
npm run js
```

To automatically compile JS when files are changed, run:

```
npm run js -- --watch
```

To cancel the watch process, type `Ctrl+c`


### SVG
To compile SVG icons run the following command.

```
npm run svg
```
