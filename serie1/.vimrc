" ---- General settings ---- "
set term=xterm-256color
if $COLORTERM == 'gnome-terminal'
  set t_Co=256
endif
" color molokai
set background=light
" set background=dark
syntax on
set autoread
set encoding=utf8
" Use Unix as the standard file type
set ffs=unix,dos,mac

"Filetype Settings
filetype plugin indent on
filetype off
filetype indent on
filetype plugin on

"No vi compatibility
set nocompatible

" A buffer becomes hidden when it is abandoned
set hid

" Automatic and smart indent
set autoindent smartindent

" Set spaces instead of tab
set smarttab
set tabstop=4
set shiftwidth=4
set softtabstop=4

" Line number
" set cursor offset
set number
set ruler
set so=10
" Show current line, and set CurrentLine color
set cul
" hi CursorLine term=none cterm=none ctermbg=black
hi CursorLine term=none cterm=underline

" Wrap long lines
set wrap
" Treat long lines as break lines (useful when moving around in them)
map j gj
map k gk

" Text width
set textwidth=120
set shiftround " round indents
set colorcolumn=80
highlight ColorColumn ctermbg=8
" highlight OverLength ctermbg=red ctermfg=white guibg=#592929
" match OverLength /\%81v.\+/

" Search options
" Incremental research
set incsearch
" Highlight things found
set hlsearch
" Ignore case when searching
set ignorecase
" When searching try to be smart about cases 
set smartcase
" For regular expressions turn magic on
set magic
filetype plugin on
set omnifunc=syntaxcomplete#Complete

" Don't redraw while executing macros (good performance config)
set lazyredraw

" Return to last edit position when opening files (You want this!)
autocmd BufReadPost *
     \ if line("'\"") > 0 && line("'\"") <= line("$") |
     \   exe "normal! g`\"" |
     \ endif

autocmd WinEnter * call s:CloseIfOnlyNerdTreeLeft()

" Close all open buffers on entering a window if the only
" buffer that's left is the NERDTree buffer
function! s:CloseIfOnlyNerdTreeLeft()
  if exists("t:NERDTreeBufName")
    if bufwinnr(t:NERDTreeBufName) != -1
      if winnr("$") == 1
        q
      endif
    endif
  endif
endfunction

" History length
set history=700

" Wildmenu
set wildmenu
set wildmode=list:longest,full
set wildignore=*.o,*~,*.pyc,*.class

" Pathogen
execute pathogen#infect()

" Vundle
set rtp+=~/.vim/bundle/vundle
call vundle#rc()

" let Vundle manage Vundle
" required! 
Bundle 'gmarik/vundle'

" Indent Guides
let g:indent_guides_auto_colors = 0
let g:indent_guides_guide_size = 1
let g:indent_guides_start_level = 2
autocmd VimEnter,Colorscheme * :hi IndentGuidesOdd ctermbg=8
autocmd VimEnter,Colorscheme * :hi IndentGuidesEven ctermbg=black
" autocmd VimEnter,Colorscheme * :IndentGuidesEnable

highlight ExtraWhitespace ctermbg=9

syntax enable
filetype plugin indent on

" No annoying sound on errors
set noerrorbells
set novisualbell
set t_vb=
set tm=500

"""""""""""""""""""""""""""""""""""
"            Mappings             "
"""""""""""""""""""""""""""""""""""

"imap <A-i> <ESC>

" Open NERD_tree
map <F2> :NERDTreeToggle<CR>

" Correct frequent typos
:command WQ wq
:command Wq wq
:command Qw wq
:command Q q
:command W w

