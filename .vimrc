" It is recommended to alter the value of the 'compatible' option
" before making any change
"set compatible             " As compatible with the original Vi as possible
"set nocompatible           " Use Vim defaults instead of 100% Vi compatibility
set nocompatible
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" Load plugins and indentation rules according to the detected filetype
filetype plugin indent on

syntax on                   " Enable syntax highlighting

set number                  " Display line number

set mouse=                  " Disable mouse usage (modes: n, v, i, c, h, a)

set hidden                  " Hide buffers when they are abandoned

" Jump to the last position when reopening a file
au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif

" Status related
set ruler           " Show the cursor position all the time
set showcmd         " Show (partial) command in status line
set showmode        " Show mode
set autowrite       " Automatically save before commands like :next and :make

" Indentation related
set autoindent      " Auto indent new line with current line's indent status
set smartindent     " Improved autoindent
set cindent         " Indent using c language style
"if exists('+colorcolumn')
"    set colorcolumn=80
"else
"    au BufWinEnter * let w:m2=matchadd('ErrorMsg', '\%>80v.\+', -1)
"endif
nnoremap <F2> :set invpaste paste?<CR>
imap <F2> <C-O>:set invpaste paste?<CR>
set pastetoggle=<F2>
set shiftround      " Align with around
set tabstop=4       " Tab width
set expandtab       " Use blank space instead of tab
set shiftwidth=4    " Indent between levels
set softtabstop=4   " Delete 4 blank space when using backspace
set smarttab        " Use tab at the beginning of line and paragraph
set backspace=indent,eol,start      " More powerful backspacing

" Search related
set hlsearch        " DO highlighted searching
set incsearch       " DO incremental searching
set smartcase       " DO smart case matching
set ignorecase      " DO case insensitive matching
set showmatch       " Show matching brackets

" Auto completion <C-p>
set completeopt=longest,menuone

inoremap <expr> <CR> pumvisible() ? "\<C-y>" : "\<C-g>u\<CR>"

inoremap <expr> <C-n> pumvisible() ? '<C-n>' :
  \ '<C-n><C-r>=pumvisible() ? "\<lt>Down>" : ""<CR>'

inoremap <expr> <M-,> pumvisible() ? '<C-n>' :
  \ '<C-x><C-o><C-n><C-p><C-r>=pumvisible() ? "\<lt>Down>" : ""<CR>'

if ! has("gui_running")
    set t_Co=256
endif

if &diff
    set background=light "dark
    colors peaksea
endif

" set fold mode
" set fdm=indent

set tags=tags;
set autochdir
