" =======================================
" vim-plug (https://github.com/junegunn/vim-plug/)

" Specify a directory for plugins
" - For Neovim: stdpath('data') . '/plugged'
" - Avoid using standard Vim directory names like 'plugin'
call plug#begin('~/.vim/plugged')

" Make sure using single quotes

if 1
    " vim-airline (https://github.com/vim-airline/vim-airline/)
    if 1
        Plug 'git://github.com/vim-airline/vim-airline.git'
        Plug 'git://github.com/vim-airline/vim-airline-themes.git'
        let g:airline#extensions#tabline#enabled = 1
        let g:airline_theme='simple'
    endif
    " lightline.vim (https://github.com/itchyny/lightline.vim/)
    if 0
        Plug 'git://github.com/itchyny/lightline.vim.git'
        "let g:lightline = {'colorscheme': 'wombat',}
        set laststatus=2
    endif
    " rainbow (https://github.com/luochen1990/rainbow/)
    if 1
        Plug 'git://github.com/luochen1990/rainbow.git'
        let g:rainbow_active = 1 "0 if you want to enable it later via :RainbowToggle
    endif
endif

" The NERDTree (https://github.com/preservim/nerdtree/)
if 0
    Plug 'git://github.com/preservim/nerdtree.git'
    let g:NERDTreeShowLineNumbers=1
    let g:NERDTreeWinSize=39
    let g:NERDTreeDirArrowExpandable = '+'
    let g:NERDTreeDirArrowCollapsible = '-'
    autocmd VimEnter * NERDTree | wincmd p " Start NERDTree and put the cursor back in the other window.
endif

" Conquer of Completion (https://github.com/neoclide/coc.nvim/)
if 1
    Plug 'git://github.com/neoclide/coc.nvim.git', {'branch': 'release'}
endif

" Goyo (고요) (https://github.com/junegunn/goyo.vim/)
if 1
    Plug 'git://github.com/junegunn/goyo.vim.git'
endif

" vim-pencil (https://github.com/preservim/vim-pencil/)
if 1
    Plug 'git://github.com/preservim/vim-pencil.git'
endif

" vim-wenyan (https://github.com/voldikss/vim-wenyan/)
if 1
    Plug 'git://github.com/voldikss/vim-wenyan.git'
endif


" Initialize plugin system
call plug#end()
" =======================================

syntax enable
set nocompatible
set autoindent
set cindent
set tabstop=4
set softtabstop=4
set shiftwidth=4
set expandtab
set number
set cursorline
filetype plugin on
set backspace=2
set showmatch
if has('gui_running')
    set background=light
    colorscheme solarized
    set guifont=Fixedsys:h14
else
    set background=dark
endif
